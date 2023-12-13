QT += core gui

#QT_CONFIG -= no-pkg-config
#CONFIG += link_pkgconfig
#PKGCONFIG += opencv

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qt-opencv-multithreaded
TEMPLATE = app
DESTDIR = $$PWD
DEFINES += APP_VERSION=\\\"1.3.2\\\"

SOURCES += main.cpp \
    MainWindow.cpp \
    MatToQImage.cpp \
    FrameLabel.cpp \
    CameraView.cpp \
    ProcessingThread.cpp \
    CaptureThread.cpp \
    CameraConnectDialog.cpp \
    ImageProcessingSettingsDialog.cpp \
    SharedImageBuffer.cpp \
    faceDetector.cpp

HEADERS += \
    MainWindow.h \
    Config.h \
    MatToQImage.h \
    FrameLabel.h \
    Structures.h \
    CameraView.h \
    ProcessingThread.h \
    CaptureThread.h \
    CameraConnectDialog.h \
    ImageProcessingSettingsDialog.h \
    SharedImageBuffer.h \
    Buffer.h \
    faceDetector.h

FORMS += \
    MainWindow.ui \
    CameraView.ui \
    CameraConnectDialog.ui \
    ImageProcessingSettingsDialog.ui

    #Linux opencv link
    # OpenCv Configuration opencv-4.2.0
    INCLUDEPATH += "/usr/include/opencv4/opencv2"
    INCLUDEPATH += "/usr/include/opencv4"


#    LIBS += -L~/usr/lib/x86_64-linux-gnu \
#    -lopencv_core \
#    -lopencv_highgui \
#    -lopencv_imgproc \
#    -lopencv_features2d \
#    -lopencv_calib3d \
#    -lopencv_video\
#    -lopencv_videoio\
#    -lopencv_aruco

    INCLUDEPATH += "D:\OpenCV\OpenCV-MinGW-Build-OpenCV-4.5.0-with-contrib\include"
    INCLUDEPATH += "D:\OpenCV\OpenCV-MinGW-Build-OpenCV-4.5.0-with-contrib\include\opencv2"

    LIBS += -LD:\OpenCV\OpenCV-MinGW-Build-OpenCV-4.5.0-with-contrib\x64\mingw\bin\
    -lopencv_core450 \
    -lopencv_highgui450 \
    -lopencv_imgproc450 \
    -lopencv_features2d450 \
    -lopencv_calib3d450\
    -lopencv_video450\
    -lopencv_videoio450\
    -lopencv_videostab450\
    -lopencv_objdetect450\
    -lopencv_imgcodecs450\
    -lopencv_aruco450

QMAKE_CXXFLAGS += -Wall
