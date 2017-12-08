#include <QApplication>
#include <vtkAutoInit.h>
#include "mainwindow.h"

int main(int argc, char** argv) {
    VTK_MODULE_INIT(vtkRenderingOpenGL2);
    VTK_MODULE_INIT(vtkRenderingFreeType);
    VTK_MODULE_INIT(vtkInteractionStyle);    
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
