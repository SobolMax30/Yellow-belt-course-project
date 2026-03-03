TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += /usr/include
INCLUDEPATH += /usr/local/include

QMAKE_CXXFLAGS += -isystem /usr/include/c++/9
QMAKE_CXXFLAGS += -isystem /usr/include/x86_64-linux-gnu/c++/9
QMAKE_CXXFLAGS += -isystem /usr/include/c++/9/backward
QMAKE_CXXFLAGS += -isystem /usr/lib/gcc/x86_64-linux-gnu/9/include
QMAKE_CXXFLAGS += -isystem /usr/local/include
QMAKE_CXXFLAGS += -isystem /usr/include/x86_64-linux-gnu
QMAKE_CXXFLAGS += -isystem /usr/include

QMAKE_CXXFLAGS += -m64

QMAKE_CXXFLAGS += --sysroot=/

SOURCES += \
    condition_parser.cpp \
    database.cpp \
    date.cpp \
    main.cpp \
    node.cpp \
    test_runner.cpp \
    token.cpp \
    unit_tests.cpp

HEADERS += \ \
    condition_parser.h \
    database.h \
    date.h \
    node.h \
    test_runner.h \
    token.h

