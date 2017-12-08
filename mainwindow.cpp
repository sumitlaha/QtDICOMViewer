#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    setUI();

    // Assign renderer to views
    renderer = vtkSmartPointer<vtkRenderer>::New();
    ui->qvtkWidgetAxl->GetRenderWindow()->AddRenderer(renderer);
    ui->qvtkWidgetCor->GetRenderWindow()->AddRenderer(renderer);
    ui->qvtkWidgetSag->GetRenderWindow()->AddRenderer(renderer);


}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::openDICOMFolder() {    
    folderNameDICOM = QFileDialog::getExistingDirectory(this, tr("Open DICOM Image/Folder"), "/", QFileDialog::ShowDirsOnly);
    if(!folderNameDICOM.isEmpty()) {
        initialization();
        drawDICOMSeries(folderNameDICOM.toUtf8().constData());
    }
}

void MainWindow::drawDICOMSeries(std::string folderDICOM) {
    //Read the input series
    inputNames->SetInputDirectory(folderDICOM.c_str());
    const ReaderType::FileNamesContainer & filenames = inputNames->GetInputFileNames();
    reader->SetImageIO(gdcmIO);
    reader->SetFileNames(filenames);
    try {
        reader->Update();
    } catch (itk::ExceptionObject &excp) {
        std::cerr << "Exception thrown while reading the series" << std::endl;
        std::cerr << excp << std::endl;
    }

    //Connector to convert ITK image data to VTK image data
    connector->SetInput(reader->GetOutput()); //Set ITK reader Output to connector you can replace it with filter
    try { //Exceptional handling
        connector->Update();
    } catch (itk::ExceptionObject & e) {
        std::cerr << "exception in file reader " << std::endl;
        std::cerr << e << std::endl;
    }

    //Deep copy connector's output to an image else connector will go out of scope and vanish it will cause error while changing slice
    image->DeepCopy(connector->GetOutput());

    //Read MetaData
    readMetaData();

    //Set VTK Viewer to QVTKWidget
    showAxl();
    showCor();
    showSag();

    //Update Statusbar
    statusLabelSlices->setText("Images: "+QString::number(maxSliceAxl+1));
    statusLabelFolder->setText("DIR: "+QString::fromStdString(folderDICOM));
}

void MainWindow::showAxl() {
    //Set input image to VTK viewer
    viewerAxl->SetInputData(image);

    //Flipping Y-axis (further checking needed)
    cam = viewerAxl->GetRenderer()->GetActiveCamera();
    cam->SetPosition(0,0,-1);
    cam->SetViewUp(0,-1,0);

    ui->qvtkWidgetAxl->SetRenderWindow(viewerAxl->GetRenderWindow());
    viewerAxl->SetupInteractor(ui->qvtkWidgetAxl->GetRenderWindow()->GetInteractor());    
    viewerAxl->SetSliceOrientationToXY();

    // Gets the number of slices
    minSliceAxl = viewerAxl->GetSliceMin();
    maxSliceAxl = viewerAxl->GetSliceMax();
    viewerAxl->SetSlice(viewerAxl->GetSliceMax()/2);
    viewerAxl->GetRenderer()->ResetCamera();
    viewerAxl->Render();
    ui->qvtkWidgetAxl->update();

    // Update GUI Labels
    ui->hScrollBarAxl->setMinimum(minSliceAxl);
    ui->hScrollBarAxl->setMaximum(maxSliceAxl);
    ui->hScrollBarAxl->setSliderPosition(maxSliceAxl/2);
    ui->lblCurrentSliceAxl->setText("Slice: "+QString::number(viewerAxl->GetSlice()+1)+" of "+QString::number(maxSliceAxl+1));
}

void MainWindow::showCor() {
    //Set input image to VTK viewer
    viewerCor->SetInputData(image);

    ui->qvtkWidgetCor->SetRenderWindow(viewerCor->GetRenderWindow());
    viewerCor->SetupInteractor(ui->qvtkWidgetCor->GetRenderWindow()->GetInteractor());
    viewerCor->SetSliceOrientationToXZ();

    // Gets the number of slices
    minSliceCor = viewerCor->GetSliceMin();
    maxSliceCor = viewerCor->GetSliceMax();
    viewerCor->SetSlice(viewerCor->GetSliceMax()/2);
    viewerCor->GetRenderer()->ResetCamera();
    viewerCor->Render();
    ui->qvtkWidgetCor->update();

    // Update GUI Labels
    ui->hScrollBarCor->setMinimum(minSliceCor);
    ui->hScrollBarCor->setMaximum(maxSliceCor);
    ui->hScrollBarCor->setSliderPosition(maxSliceCor/2);
    ui->lblCurrentSliceCor->setText("Slice: "+QString::number(viewerCor->GetSlice()+1)+" of "+QString::number(maxSliceCor+1));
}

void MainWindow::showSag() {
    //Set input image to VTK viewer
    viewerSag->SetInputData(image);

    ui->qvtkWidgetSag->SetRenderWindow(viewerSag->GetRenderWindow());
    viewerSag->SetupInteractor(ui->qvtkWidgetSag->GetRenderWindow()->GetInteractor());
    viewerSag->SetSliceOrientationToYZ();

    // Gets the number of slices
    minSliceSag = viewerSag->GetSliceMin();
    maxSliceSag = viewerSag->GetSliceMax();
    viewerSag->SetSlice(viewerSag->GetSliceMax()/2);
    viewerSag->GetRenderer()->ResetCamera();
    viewerSag->Render();
    ui->qvtkWidgetSag->update();

    // Update GUI Labels
    ui->hScrollBarSag->setMinimum(minSliceSag);
    ui->hScrollBarSag->setMaximum(maxSliceSag);
    ui->hScrollBarSag->setSliderPosition(maxSliceSag/2);
    ui->lblCurrentSliceSag->setText("Slice: "+QString::number(viewerSag->GetSlice()+1)+" of "+QString::number(maxSliceSag+1));
}

void MainWindow::setUI() {
    ui->toolBar->setStyleSheet("QToolBar{background:silver;}");
    ui->tableMetaData->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    on_actionImageMetaData_triggered(false);
    // Create status bar
    statusLabelSlices = new QLabel(this);
    statusLabelFolder = new QLabel(this);
    statusLabelSlices->setText("Images:");
    statusLabelFolder->setText("DIR:");
    ui->statusBar->addPermanentWidget(statusLabelSlices,1);
    ui->statusBar->addPermanentWidget(statusLabelFolder);
}

void MainWindow::on_actionOpen_triggered() {
    openDICOMFolder();
}

void MainWindow::on_actionExit_triggered() {
    QApplication::quit();
}

void MainWindow::on_hScrollBarAxl_valueChanged(int value) {
    viewerAxl->SetSlice(value);
    ui->lblCurrentSliceAxl->setText("Slice: "+QString::number(viewerAxl->GetSlice()+1)+" of "+QString::number(maxSliceAxl+1));
    viewerAxl->Render();
}

void MainWindow::on_hScrollBarCor_valueChanged(int value) {
    viewerCor->SetSlice(value);
    ui->lblCurrentSliceCor->setText("Slice: "+QString::number(viewerCor->GetSlice()+1)+" of "+QString::number(maxSliceCor+1));
    viewerCor->Render();
}

void MainWindow::on_hScrollBarSag_valueChanged(int value) {
    viewerSag->SetSlice(value);
    ui->lblCurrentSliceSag->setText("Slice: "+QString::number(viewerSag->GetSlice()+1)+" of "+QString::number(maxSliceSag+1));
    viewerSag->Render();
}

void MainWindow::readMetaData() {
    const  DictionaryType & dictionary = gdcmIO->GetMetaDataDictionary();
    itr = dictionary.Begin();
    end = dictionary.End();

    while(itr != end) {
        entry = itr->second;
        entryvalue = dynamic_cast<MetaDataStringType *>(entry.GetPointer());
        if(entryvalue) {
            std::string labelId;
            std::string tagkey = itr->first;
            std::string tagvalue = entryvalue->GetMetaDataObjectValue();
            itk::GDCMImageIO::GetLabelFromTag(tagkey,labelId);
            int insertRow = ui->tableMetaData->rowCount();
            ui->tableMetaData->insertRow(insertRow);
            ui->tableMetaData->setItem(insertRow,0,new QTableWidgetItem(labelId.c_str()));
            ui->tableMetaData->setItem(insertRow,1,new QTableWidgetItem(tagvalue.c_str()));
        }
        ++itr;
    }
}

void MainWindow::on_actionImageMetaData_triggered(bool checked) {
    if(checked) {
        ui->lblImageMetaData->setVisible(true);
        ui->tableMetaData->setVisible(true);
    } else {
        ui->lblImageMetaData->setVisible(false);
        ui->tableMetaData->setVisible(false);
    }
}

void MainWindow::on_actionRefresh_triggered() {
    viewerAxl->GetRenderer()->ResetCamera();
    viewerCor->GetRenderer()->ResetCamera();
    viewerSag->GetRenderer()->ResetCamera();
    viewerAxl->Render();
    viewerCor->Render();
    viewerSag->Render();
}

void MainWindow::initialization() {
    //Initializaton
    viewerAxl = vtkSmartPointer<vtkImageViewer2>::New();
    viewerCor = vtkSmartPointer<vtkImageViewer2>::New();
    viewerSag = vtkSmartPointer<vtkImageViewer2>::New();
    gdcmIO = ImageIOType::New();
    inputNames = InputNamesGeneratorType::New();
    reader = ReaderType::New();
    connector= ConnectorType::New();
    image = vtkImageData::New();
    activeCam = vtkCamera::New();
    //Enabling and disabling GUI items
    ui->actionImageMetaData->setEnabled(true);
    ui->actionRefresh->setEnabled(true);
    ui->hScrollBarAxl->setEnabled(true);
    ui->hScrollBarCor->setEnabled(true);
    ui->hScrollBarSag->setEnabled(true);
    ui->tableMetaData->scrollToTop();
    ui->tableMetaData->setRowCount(0);
}
