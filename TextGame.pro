QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bagwidget.cpp \
    character.cpp \
    combatwidget.cpp \
    commonhelper.cpp \
    comparezb.cpp \
    createrole.cpp \
    main.cpp \
    mainwidget.cpp \
    model.cpp \
    roleinfo.cpp \
    widget.cpp \
    zbinfowidget.cpp

HEADERS += \
    bagwidget.h \
    character.h \
    combatwidget.h \
    commonhelper.h \
    comparezb.h \
    createrole.h \
    mainwidget.h \
    model.h \
    roleinfo.h \
    widget.h \
    zbinfowidget.h

FORMS += \
    bagwidget.ui \
    combatwidget.ui \
    comparezb.ui \
    createrole.ui \
    mainwidget.ui \
    model.ui \
    roleinfo.ui \
    widget.ui \
    zbinfowidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
