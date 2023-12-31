QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    controller/controller.cpp \
    main.cpp \
    parsers/matchparser.cpp \
    parsers/userWinRateParser.cpp \
    parsers/userparser.cpp \
    utils/matchurlbreaker.cpp \
    utils/networker.cpp \
    utils/urlcreator.cpp \
    mainwindow.cpp \
    model\model.cpp

HEADERS += \
    controller/controller.h \
    model/model.h \
    parsers/matchparser.h \
    parsers/userWinRateParser.h \
    parsers/userparser.h \
    utils/matchurlbreaker.h \
    utils/networker.h \
    utils/urlcreator.h \
    mainwindow.h \
    model\model.h


FORMS += \
    mainwindow.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
