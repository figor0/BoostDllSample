TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

DESTDIR = $$OUT_PWD/../bin/

INCLUDEPATH += $$PWD/../Core

SOURCES += \
        main.cpp

unix:!macx: LIBS += -L$$OUT_PWD/../bin/ -lCore
LIBS += -lboost_system -lboost_filesystem -ldl
