QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addstuinfo.cpp \
    adminmenuwidget.cpp \
    delstuinfo.cpp \
    insertstuinfo.cpp \
    main.cpp \
    adminwidget.cpp \
    modifystuinfo.cpp \
    searchstuinfo.cpp \
    sortstuinfo.cpp \
    stuinfo.cpp

HEADERS += \
    addstuinfo.h \
    adminmenuwidget.h \
    adminwidget.h \
    delstuinfo.h \
    insertstuinfo.h \
    modifystuinfo.h \
    node.h \
    searchstuinfo.h \
    sortstuinfo.h \
    stuinfo.h

FORMS += \
    addstuinfo.ui \
    adminmenuwidget.ui \
    adminwidget.ui \
    delstuinfo.ui \
    insertstuinfo.ui \
    modifystuinfo.ui \
    searchstuinfo.ui \
    sortstuinfo.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
