TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
QT -= gui
QT += core gui widgets


TARGET = YourTargetName
CONFIG += console
CONFIG -= app_bundle

SOURCES += \
    main.cpp \
    ModelInput.cpp \
    FaceDetector.cpp \
    EmotionDetection.cpp \
    ConvertToGrayScale.cpp \
    Camera.cpp \
    menuscreen.cpp

HEADERS += \
    ModelInput.h \
    FaceDetector.h \
    EmotionDetection.h \
    ConvertToGrayScale.h \
    Camera.h \
    menuscreen.h

INCLUDEPATH += /opt/homebrew/opt/opencv/include/opencv4
LIBS += -L/opt/homebrew/opt/opencv/lib \
    -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_imgcodecs -lopencv_dnn -lopencv_videoio -lopencv_objdetect

FORMS += \
    menuscreen.ui

INCLUDEPATH += $$[QT_INSTALL_HEADERS]

