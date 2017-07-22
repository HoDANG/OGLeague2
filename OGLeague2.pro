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
    netserver.cpp \
    objectmanager.cpp \
    playermanager.cpp \
    game.cpp \
    world.cpp \
    locationsmanager.cpp \
    visibilitymanager.cpp \
    spellmanager.cpp \
    scriptmanager.cpp \
    itemmanager.cpp \
    navigationmanager.cpp \
    timemanager.cpp

HEADERS += \
    netserver.h \
    objectmanager.h \
    playermanager.h \
    game.h \
    world.h \
    locationsmanager.h \
    visibilitymanager.h \
    spellmanager.h \
    scriptmanager.h \
    itemmanager.h \
    navigationmanager.h \
    timemanager.h

win32 {
    LIBS += -lws2_32 -lwinmm
}
