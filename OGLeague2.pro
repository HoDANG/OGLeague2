TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += dep

include(dep/dep.pri)
include(common/common.pri)
include(net/network.pri)
include(stats/stats.pri)
include(object/object.pri)
include(scripts/scripts.pri)
include(packets/packets.pri)

SOURCES += \
    main.cpp \
    lobby.cpp \
    netserver.cpp \
    objectmanager.cpp \
    world.cpp

HEADERS += \
    lobby.h \
    netserver.h \
    objectmanager.h \
    world.h

win32 {
    LIBS += -lws2_32 -lwinmm
}
