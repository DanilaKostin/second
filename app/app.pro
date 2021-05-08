TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += load.cpp \
    append_line.cpp \
    create_text.cpp \
    editor.cpp \
    m.cpp \
    mle.cpp \
    process_forward.cpp \
    r1ne.cpp \
    remove_all.cpp \
    showupfirst.cpp \
    show.cpp \
    save.cpp \

HEADERS += \
        text.h \
        _text.h \
        common.h

QMAKE_CFLAGS += -Wall -Wextra -Werror

# gcov
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov 
