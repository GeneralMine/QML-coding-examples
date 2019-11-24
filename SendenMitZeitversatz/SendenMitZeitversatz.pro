TEMPLATE = app

QT += qml quick widgets
QT +=sql

SOURCES += main.cpp \
    mydatabase.cpp \
    mycache.cpp \
    mysocket.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    mydatabase.h \
    mycache.h \
    mysocket.h
