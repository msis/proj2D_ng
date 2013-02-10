#-------------------------------------------------
#
# Project created by QtCreator 2013-01-28T13:38:49
#
#-------------------------------------------------

QT       += core gui

TARGET = proj2D_ng
TEMPLATE = app


SOURCES += main.cpp \
        proj2d_ng.cpp \
    ibexuser.cpp


HEADERS  += proj2d_ng.h \
    ibexuser.h

FORMS    += proj2d_ng.ui


unix:!macx:!symbian: LIBS += -L$$PWD/../../../PhD/ibex-2.0/bin/ -libex_linux_x86

INCLUDEPATH += $$PWD/../../../PhD/ibex-2.0/include/ibex
DEPENDPATH += $$PWD/../../../PhD/ibex-2.0/include/ibex

unix:!macx:!symbian: PRE_TARGETDEPS += $$PWD/../../../PhD/ibex-2.0/bin/libibex_linux_x86.a

unix:!macx:!symbian: LIBS += -L$$PWD/../../../PhD/soplex-1.7.0/lib/ -lsoplex_linux_x86

INCLUDEPATH += $$PWD/../../../PhD/soplex-1.7.0/src
DEPENDPATH += $$PWD/../../../PhD/soplex-1.7.0/src

unix:!macx:!symbian: PRE_TARGETDEPS += $$PWD/../../../PhD/soplex-1.7.0/lib/libsoplex_linux_x86.a
