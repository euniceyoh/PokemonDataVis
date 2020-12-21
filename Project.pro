DESTDIR += $$PWD
QT       += core gui
QT += charts

requires(qtConfig(combobox))
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    character.cpp \
    inputwindow.cpp \
    iorunner.cpp \
    main.cpp \
    mainwindow.cpp \
    stackedbar.cpp

HEADERS += \
    character.h \
    inputwindow.h \
    iorunner.h \
    mainwindow.h \
    stackedbar.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    Project_en_US.ts

DESTDIR += $$PWD

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=
