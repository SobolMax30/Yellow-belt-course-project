TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += /usr/include/c++/9
INCLUDEPATH += /usr/include/x86_64-linux-gnu/c++/9
INCLUDEPATH += /usr/include/c++/9/backward
INCLUDEPATH += /usr/lib/gcc/x86_64-linux-gnu/9/include
INCLUDEPATH += /usr/local/include
INCLUDEPATH += /usr/include/x86_64-linux-gnu
INCLUDEPATH += /usr/include

SOURCES += \
    condition_parser.cpp \
    database.cpp \
    date.cpp \
    main.cpp \
    node.cpp \
    test_runner.cpp \
    token.cpp \
    unit_tests.cpp

HEADERS += \
    condition_parser.h \
    database.h \
    date.h \
    node.h \
    test_runner.h \
    token.h
