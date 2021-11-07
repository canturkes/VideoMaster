QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# Add OpenCV --change
INCLUDEPATH += D:\opencv\build-msvc19\install\include
DEPENDPATH += D:\opencv\build-msvc19\install\include/opencv2
CONFIG(release, debug|release): LIBS += -LD:\opencv\build-msvc19\install\x64\vc16\lib\ -lopencv_world440
else:CONFIG(debug, debug|release): LIBS += -LD:\opencv\build-msvc19\install\x64\vc16\lib\ -lopencv_world440d
