#ifndef MainWindow_H
#define MainWindow_H

//Qt headers
#include <QMainWindow>
#include <QLabel>
#include <QTableWidget>
#include <QMouseEvent>
#include <QVTKWidget.h>
//ITK headers
#include <itkImage.h>
#include <itkGDCMImageIO.h>
#include <itkGDCMSeriesFileNames.h>
#include <itkImageSeriesReader.h>
#include <itkImageToVTKImageFilter.h>
#include <vnl/vnl_vector.hxx>
#include <vnl/algo/vnl_svd.hxx>
#include <vnl/algo/vnl_qr.hxx>
//VTK headers
#include <vtkCellPicker.h>
#include <vtkCamera.h>
#include <vtkImageData.h>
#include <vtkImageViewer2.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkSmartPointer.h>
#include <vtkPoints.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkCellArray.h>
#include <vtkProperty.h>

VNL_VECTOR_INSTANTIATE(double);
VNL_VECTOR_INSTANTIATE(float);
VNL_VECTOR_INSTANTIATE(int);
VNL_SVD_INSTANTIATE(double);
VNL_QR_INSTANTIATE(double);

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void setUI();
    void openDICOMFolder();
    void drawDICOMSeries(std::string folderDICOM);
    void initialization();
    void showAxl();
    void showCor();
    void showSag();
    void readMetaData();
    // MenuBar
    void on_actionOpen_triggered();
    void on_actionExit_triggered();
    void on_actionImageMetaData_triggered(bool checked);
    void on_actionRefresh_triggered();
    // Scrollbar
    void on_hScrollBarAxl_valueChanged(int value);
    void on_hScrollBarCor_valueChanged(int value);
    void on_hScrollBarSag_valueChanged(int value);

private:
    //Qt
    Ui::MainWindow *ui;
    QLabel *statusLabelSlices,*statusLabelFolder;
    QString folderNameDICOM;
    //ITK
    static const unsigned int InputDimension = 3;
    typedef signed short PixelType;
    typedef itk::Image<PixelType, InputDimension> InputImageType;
    typedef itk::GDCMImageIO ImageIOType;
    typedef itk::GDCMSeriesFileNames InputNamesGeneratorType;
    typedef itk::ImageSeriesReader<InputImageType> ReaderType;
    typedef itk::ImageToVTKImageFilter<InputImageType> ConnectorType;
    typedef itk::MetaDataDictionary DictionaryType;
    typedef itk::MetaDataObject<std::string> MetaDataStringType;
    DictionaryType::ConstIterator itr,end;
    itk::MetaDataObjectBase::Pointer entry;
    MetaDataStringType::Pointer entryvalue;
    ImageIOType::Pointer gdcmIO;
    InputNamesGeneratorType::Pointer inputNames;
    ReaderType::Pointer reader;
    ConnectorType::Pointer connector;
    //VTK
    vtkSmartPointer<vtkImageViewer2> viewerAxl,viewerCor,viewerSag;
    vtkSmartPointer<vtkRenderer> renderer;
    vtkImageData *image;
    vtkCamera *cam,*activeCam;
    //Misc
    int minSliceAxl,maxSliceAxl,minSliceCor,maxSliceCor,minSliceSag,maxSliceSag;
};

#endif // MainWindow_H
