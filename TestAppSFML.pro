QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0



# Подключение иконки
# RC_ICONS = sort.ico


SOURCES += \
    main.cpp \
    mainwindow.cpp \
    service.cpp

HEADERS += \
    mainwindow.h \
    service.h

FORMS += \
    mainwindow.ui

# Подключение SFML
INCLUDEPATH += C:\SFML-2.6.1-windows-vc17-64-bit\SFML-2.6.1-sources\include
DEPENDPATH += C:\SFML-2.6.1-windows-vc17-64-bit\SFML-2.6.1-sources\include

LIBS += -LC:\SFML-2.6.1-windows-vc17-64-bit\TestBuild\LIBS\

CONFIG(debug, debug|release): LIBS += -lsfml-audio-d -lsfml-system-d -lsfml-network-d -lsfml-main-d -lsfml-window-d -lsfml-graphics-d
CONFIG(release, debug|release): LIBS += -lsfml-audio-d -lsfml-system -lsfml-network -lsfml-main -lsfml-window -lsfml-graphics


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Res.qrc
