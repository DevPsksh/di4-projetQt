#-------------------------------------------------
#
# Project created by QtCreator 2018-03-21T13:46:51
#
#-------------------------------------------------

QT       += core gui sql


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtProject
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    dialoglogin.cpp \
    dialogajouterclient.cpp \
    dialogajouterressource.cpp \
    dialogapropos.cpp \
    client.cpp \
    ressource.cpp \
    compte.cpp \
    type.cpp \
    controleurclient.cpp \
    controleurressource.cpp \
    controleurtype.cpp \
    controleurcompte.cpp \
    c_init_bd.cpp \
    interfacebd.cpp \
    clienttablemodel.cpp \
    ressourcelistmodel.cpp \
    ressourcetreemodel.cpp \
    ressourcetreeitem.cpp \
    dialogajouterdivers.cpp

HEADERS += \
        mainwindow.h \
    dialoglogin.h \
    dialogajouterclient.h \
    dialogajouterressource.h \
    dialogapropos.h \
    client.h \
    ressource.h \
    compte.h \
    type.h \
    controleurclient.h \
    controleurressource.h \
    controleurtype.h \
    controleurcompte.h \
    c_init_bd.h \
    interfacebd.h \
    clienttablemodel.h \
    ressourcelistmodel.h \
    ressourcetreemodel.h \
    ressourcetreeitem.h \
    dialogajouterdivers.h

FORMS += \
        mainwindow.ui \
    dialoglogin.ui \
    dialogajouterclient.ui \
    dialogajouterressource.ui \
    dialogapropos.ui \
    dialogajouterdivers.ui

RESOURCES += \
    resources.qrc
