QT       += core gui \
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Controllers/global_views_controller.cpp \
    Controllers/level_controller.cpp \
    Main.cpp \
    Models/alive_entity.cpp \
    Models/block.cpp \
    Models/entity.cpp \
    Models/goomba.cpp \
    Models/ground.cpp \
    Models/interface_visitable.cpp \
    Models/interface_visitor.cpp \
    Models/koopa.cpp \
    Models/level.cpp \
    Models/mario.cpp \
    Models/peach.cpp \
    Models/static_entity.cpp \
    Tools/controls.cpp \
    Views/game_view.cpp \
    Views/game_view_entity.cpp \
    Views/game_view_factory.cpp \
    Views/global_view.cpp \
    Views/viewtest.cpp


HEADERS += \
    Controllers/global_views_controller.h \
    Controllers/level_controller.h \
    Models/alive_entity.h \
    Models/block.h \
    Models/entity.h \
    Models/goomba.h \
    Models/ground.h \
    Models/interface_visitable.h \
    Models/interface_visitor.h \
    Models/koopa.h \
    Models/level.h \
    Models/mario.h \
    Models/peach.h \
    Models/static_entity.h \
    Tools/controls.h \
    Views/game_view.h \
    Views/game_view_entity.h \
    Views/game_view_factory.h \
    Views/global_view.h \
    Views/viewtest.h

FORMS += \


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc \
    res.qrc \
    res.qrc

DISTFILES +=
