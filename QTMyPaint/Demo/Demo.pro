#-------------------------------------------------
#
# Project created by QtCreator 2015-04-02T23:12:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mypaint_test
TEMPLATE = app


SOURCES += \
    $$PWD/main.cpp\
    $$PWD/mainwindow.cpp \
    $$PWD/mypaintview.cpp \
    $$PWD/PuMPBrushes.cpp \
    spinslider.cpp


HEADERS  += \
    $$PWD/mainwindow.h \
    $$PWD/mypaintview.h \
    $$PWD/PuMPBrushes.h \
    spinslider.h

FORMS    += \
    $$PWD/mainwindow.ui






# --- QTMyPaint ---
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QTMyPaint/release/ -lQTMyPaint
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QTMyPaint/debug/ -lQTMyPaint
else:unix: LIBS += -L$$OUT_PWD/../QTMyPaint/ -lQTMyPaint

INCLUDEPATH += $$PWD/../QTMyPaint
DEPENDPATH += $$PWD/../QTMyPaint

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../QTMyPaint/release/libQTMyPaint.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../QTMyPaint/debug/libQTMyPaint.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../QTMyPaint/release/QTMyPaint.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../QTMyPaint/debug/QTMyPaint.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../QTMyPaint/libQTMyPaint.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../libmypaint/release/ -llibmypaint
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../libmypaint/debug/ -llibmypaint
else:unix: LIBS += -L$$OUT_PWD/../libmypaint/ -llibmypaint

INCLUDEPATH += $$PWD/../libmypaint
DEPENDPATH += $$PWD/../libmypaint



win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../libmypaint/release/liblibmypaint.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../libmypaint/debug/liblibmypaint.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../libmypaint/release/libmypaint.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../libmypaint/debug/libmypaint.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../libmypaint/liblibmypaint.a

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../build-QTMyPaint-Desktop_Qt_5_5_0_MSVC2013_64bit-Debug/libmypaint/release/ -llibmypaint
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../build-QTMyPaint-Desktop_Qt_5_5_0_MSVC2013_64bit-Debug/libmypaint/debug/ -llibmypaint
else:unix: LIBS += -L$$PWD/../../build-QTMyPaint-Desktop_Qt_5_5_0_MSVC2013_64bit-Debug/libmypaint/ -llibmypaint

INCLUDEPATH += $$PWD/../../build-QTMyPaint-Desktop_Qt_5_5_0_MSVC2013_64bit-Debug/libmypaint/debug
DEPENDPATH += $$PWD/../../build-QTMyPaint-Desktop_Qt_5_5_0_MSVC2013_64bit-Debug/libmypaint/debug


win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../build-QTMyPaint-Desktop_Qt_5_5_0_MSVC2013_64bit-Debug/libmypaint/release/liblibmypaint.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../build-QTMyPaint-Desktop_Qt_5_5_0_MSVC2013_64bit-Debug/libmypaint/debug/liblibmypaint.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../build-QTMyPaint-Desktop_Qt_5_5_0_MSVC2013_64bit-Debug/libmypaint/release/libmypaint.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../build-QTMyPaint-Desktop_Qt_5_5_0_MSVC2013_64bit-Debug/libmypaint/debug/libmypaint.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../build-QTMyPaint-Desktop_Qt_5_5_0_MSVC2013_64bit-Debug/libmypaint/liblibmypaint.a

RESOURCES += \
    penstyle.qrc

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../build-QTMyPaint-Desktop_Qt_5_5_0_MSVC2013_64bit-Debug/json-c/release/ -ljson-c
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../build-QTMyPaint-Desktop_Qt_5_5_0_MSVC2013_64bit-Debug/Git/json-c/debug/ -ljson-c
else:unix: LIBS += -L$$PWD/../../build-QTMyPaint-Desktop_Qt_5_5_0_MSVC2013_64bit-Debu/json-c/ -ljson-c

INCLUDEPATH += $$PWD/../../build-QTMyPaint-Desktop_Qt_5_5_0_MSVC2013_64bit-Debug/json-c/debug
DEPENDPATH += $$PWD/../../build-QTMyPaint-Desktop_Qt_5_5_0_MSVC2013_64bit-Debug/json-c/debug

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../build-QTMyPaint-Desktop_Qt_5_5_0_MSVC2013_64bit-Debug/json-c/release/libjson-c.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../build-QTMyPaint-Desktop_Qt_5_5_0_MSVC2013_64bit-Debug/json-c/debug/libjson-c.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../build-QTMyPaint-Desktop_Qt_5_5_0_MSVC2013_64bit-Debug/json-c/release/json-c.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../build-QTMyPaint-Desktop_Qt_5_5_0_MSVC2013_64bit-Debug/json-c/debug/json-c.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../build-QTMyPaint-Desktop_Qt_5_5_0_MSVC2013_64bit-Debug/json-c/libjson-c.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../json-c/release/ -ljson-c
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../json-c/debug/ -ljson-c
else:unix: LIBS += -L$$OUT_PWD/../json-c/ -ljson-c

INCLUDEPATH += $$PWD/../json-c
DEPENDPATH += $$PWD/../json-c

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../json-c/release/libjson-c.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../json-c/debug/libjson-c.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../json-c/release/json-c.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../json-c/debug/json-c.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../json-c/libjson-c.a
