#-------------------------------------------------
#
# Project created by QtCreator 2014-05-25T08:28:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RuneMagic
TEMPLATE = app


SOURCES += main.cpp\
    Magic_system/spell.cpp \
    Magic_system/object.cpp \
    Magic_system/magic.cpp \
    Magic_system/character.cpp \
    Magic_system/runes/urazrune.cpp \
    Magic_system/runes/rune.cpp \
    Magic_system/runes/fehurune.cpp \
    Magic_system/runes/effects.cpp \
    gui/spelleditor.cpp \
    gui/runebutton.cpp \
    gui/data.cpp \
    gui/editor.cpp \
    gui/runesbar.cpp \
    Magic_system/runes/thurisazrune.cpp

HEADERS  += \
    Magic_system/spell.h \
    Magic_system/object.h \
    Magic_system/magic.h \
    Magic_system/character.h \
    Magic_system/runes/urazrune.h \
    Magic_system/runes/rune.h \
    Magic_system/runes/fehurune.h \
    Magic_system/runes/effects.h \
    Magic_system/runes/allrunes.h \
    gui/spelleditor.h \
    gui/runebutton.h \
    gui/data.h \
    gui/editor.h \
    gui/runesbar.h \
    Magic_system/runes/thurisazrune.h

RESOURCES += \
    resources.qrc

OTHER_FILES += \
    files/runes.inf
