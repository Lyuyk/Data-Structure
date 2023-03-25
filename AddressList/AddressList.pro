QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addfile.cpp \
    createwidget.cpp \
    insertwidget.cpp \
    linkedlist.cpp \
    main.cpp \
    mainwindow.cpp \
    searchdeletewidget.cpp \
    showwidget.cpp \
    stack.cpp \
    student.cpp

HEADERS += \
    addfile.h \
    completeBinaryTree.h \
    createwidget.h \
    insertwidget.h \
    linkedlist.h \
    mainwindow.h \
    queue.h \
    searchdeletewidget.h \
    showwidget.h \
    stack.h \
    student.h

FORMS += \
    addfile.ui \
    createwidget.ui \
    insertwidget.ui \
    mainwindow.ui \
    searchdeletewidget.ui \
    showwidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
