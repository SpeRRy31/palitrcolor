QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aboutdialog.cpp \
    color.cpp \
    createcolordialog.cpp \
    logfile.cpp \
    logindialog.cpp \
    main.cpp \
    mainwindow.cpp \
    palettelist.cpp \
    palitr.cpp \
    showcolordialog.cpp \
    sqllitedbmanager.cpp \
    user.cpp

HEADERS += \
    aboutdialog.h \
    color.h \
    createcolordialog.h \
    dbmanager.h \
    logfile.h \
    logindialog.h \
    mainwindow.h \
    palettelist.h \
    palitr.h \
    palitrcolor.h \
    showcolordialog.h \
    sqllitedbmanager.h \
    user.h

FORMS += \
    aboutdialog.ui \
    createcolordialog.ui \
    logindialog.ui \
    mainwindow.ui \
    palettelist.ui \
    showcolordialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
