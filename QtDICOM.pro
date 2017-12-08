#-------------------------------------------------
#
# Project created by QtCreator 2017-06-28T13:13:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtDICOM
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp \
        mainwindow.cpp \
    itkimageiobase.cpp

HEADERS += mainwindow.h

FORMS += mainwindow.ui

QMAKE_CXXFLAGS += -Wno-deprecated

LIBS += -L/usr/local/lib \
-lvtkalglib \
-lvtkChartsCore \
-lvtkCommonColor \
-lvtkCommonComputationalGeometry \
-lvtkCommonCore \
-lvtkCommonDataModel \
-lvtkCommonExecutionModel \
-lvtkCommonMath \
-lvtkCommonMisc \
-lvtkCommonSystem \
-lvtkCommonTransforms \
-lvtkDICOMParser \
-lvtkDomainsChemistry \
-lvtkDomainsChemistryOpenGL2 \
-lvtkexoIIc \
-lvtkexpat \
-lvtkFiltersAMR \
-lvtkFiltersCore \
-lvtkFiltersExtraction \
-lvtkFiltersFlowPaths \
-lvtkFiltersGeneral \
-lvtkFiltersGeneric \
-lvtkFiltersGeometry \
-lvtkFiltersHybrid \
-lvtkFiltersHyperTree \
-lvtkFiltersImaging \
-lvtkFiltersModeling \
-lvtkFiltersParallel \
-lvtkFiltersParallelImaging \
-lvtkFiltersPoints \
-lvtkFiltersProgrammable \
-lvtkFiltersSelection \
-lvtkFiltersSMP \
-lvtkFiltersSources \
-lvtkFiltersStatistics \
-lvtkFiltersTexture \
-lvtkFiltersTopology \
-lvtkFiltersVerdict \
-lvtkfreetype \
-lvtkGeovisCore \
-lvtkgl2ps \
-lvtkglew \
-lvtkGUISupportQt \
-lvtkGUISupportQtSQL \
-lvtkhdf5 \
-lvtkhdf5_hl \
-lvtkImagingColor \
-lvtkImagingCore \
-lvtkImagingFourier \
-lvtkImagingGeneral \
-lvtkImagingHybrid \
-lvtkImagingMath \
-lvtkImagingMorphological \
-lvtkImagingSources \
-lvtkImagingStatistics \
-lvtkImagingStencil \
-lvtkInfovisCore \
-lvtkInfovisLayout \
-lvtkInteractionImage \
-lvtkInteractionStyle \
-lvtkInteractionWidgets \
-lvtkIOAMR \
-lvtkIOCore \
-lvtkIOEnSight \
-lvtkIOExodus \
-lvtkIOExport \
-lvtkIOExportOpenGL2 \
-lvtkIOGeometry \
-lvtkIOImage \
-lvtkIOImport \
-lvtkIOInfovis \
-lvtkIOLegacy \
-lvtkIOLSDyna \
-lvtkIOMINC \
-lvtkIOMovie \
-lvtkIONetCDF \
-lvtkIOParallel \
-lvtkIOParallelXML \
-lvtkIOPLY \
-lvtkIOSQL \
-lvtkIOTecplotTable \
-lvtkIOVideo \
-lvtkIOXML \
-lvtkIOXMLParser \
-lvtkjpeg \
-lvtkjsoncpp \
-lvtklibharu \
-lvtklibxml2 \
-lvtklz4 \
-lvtkmetaio \
-lvtkNetCDF \
-lvtknetcdf_c++ \
-lvtkoggtheora \
-lvtkParallelCore \
-lvtkpng \
-lvtkproj4 \
-lvtkRenderingAnnotation \
-lvtkRenderingContext2D \
-lvtkRenderingContextOpenGL2 \
-lvtkRenderingCore \
-lvtkRenderingFreeType \
-lvtkRenderingGL2PSOpenGL2 \
-lvtkRenderingImage \
-lvtkRenderingLabel \
-lvtkRenderingLOD \
-lvtkRenderingOpenGL2 \
-lvtkRenderingQt \
-lvtkRenderingVolume \
-lvtkRenderingVolumeOpenGL2 \
-lvtksqlite \
-lvtksys \
-lvtktiff \
-lvtkverdict \
-lvtkViewsContext2D \
-lvtkViewsCore \
-lvtkViewsInfovis \
-lvtkViewsQt \
-lvtkzlib

INCLUDEPATH += /usr/local/include/vtk-8.0

LIBS += -L/usr/local/lib \
-lITKBiasCorrection \
-lITKBioCell \
-lITKCommon \
-lITKDICOMParser \
-litkdouble-conversion \
-lITKEXPAT \
-lITKFEM \
-litkgdcmcharls \
-litkgdcmCommon \
-litkgdcmDICT \
-litkgdcmDSED \
-litkgdcmIOD \
-litkgdcmjpeg8 \
-litkgdcmjpeg12 \
-litkgdcmjpeg16 \
-litkgdcmMEXD \
-litkgdcmMSFF \
-litkgdcmopenjpeg \
-litkgdcmsocketxx \
-litkgdcmuuid \
-lITKgiftiio \
-litkhdf5 \
-litkhdf5_cpp \
-lITKIOBioRad \
-lITKIOBMP \
-lITKIOCSV \
-lITKIOGDCM \
-lITKIOGE \
-lITKIOGIPL \
-lITKIOHDF5 \
-lITKIOImageBase \
-lITKIOIPL \
-lITKIOJPEG \
-lITKIOLSM \
-lITKIOMesh \
-lITKIOMeta \
-lITKIOMRC \
-lITKIONIFTI \
-lITKIONRRD \
-lITKIOPNG \
-lITKIOSiemens \
-lITKIOSpatialObjects \
-lITKIOStimulate \
-lITKIOTIFF \
-lITKIOTransformBase \
-lITKIOTransformHDF5 \
-lITKIOTransformInsightLegacy \
-lITKIOTransformMatlab \
-lITKIOVTK \
-lITKIOXML \
-litkjpeg \
-lITKKLMRegionGrowing \
-lITKLabelMap \
-lITKMesh \
-lITKMetaIO \
-litknetlib \
-litkNetlibSlatec \
-lITKniftiio \
-lITKNrrdIO \
-lITKOptimizers \
-lITKOptimizersv4 \
-lITKPath \
-litkpng \
-lITKPolynomials \
-lITKQuadEdgeMesh \
-lITKSpatialObjects \
-lITKStatistics \
-litksys \
-litktestlib \
-litktiff \
-lITKTransform \
-lITKTransformFactory \
-litkv3p_netlib \
-litkvcl \
-lITKVideoCore \
-lITKVideoIO \
-litkvnl \
-litkvnl_algo \
-lITKVNLInstantiation \
-lITKVTK \
-lITKVtkGlue \
-lITKWatersheds \
-litkzlib \
-lITKznz

LIBS += -ldl

INCLUDEPATH += /usr/local/include/ITK-4.12

LIBS += "/usr/lib/x86_64-linux-gnu/*.so.2.6.3"
#-lgdcmIOD \
#-lgdcmDICT \
#-lgdcmDSED \
#-lgdcmMEXD \
#-lgdcmMSFF \
#-lgdcmjpeg8 \
#-lgdcmCommon \
#-lgdcmjpeg12 \
#-lgdcmjpeg16

INCLUDEPATH += /usr/include/gdcm-2.6

RESOURCES += images.qrc
