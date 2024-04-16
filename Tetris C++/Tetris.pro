QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    case.cpp \
    main.cpp \
    mainwindow.cpp \
    partie.cpp \
    puits.cpp \
    tetrominos.cpp \
    tetrominos1.cpp \
    tetrominos2.cpp \
    tetrominos3.cpp \
    tetrominos4.cpp \
    tetrominos5.cpp \
    tetrominos6.cpp \
    tetrominos7.cpp

HEADERS += \
    case.h \
    mainwindow.h \
    partie.h \
    puits.h \
    tetrominos.h \
    tetrominos1.h \
    tetrominos2.h \
    tetrominos3.h \
    tetrominos4.h \
    tetrominos5.h \
    tetrominos6.h \
    tetrominos7.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
