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
    Controllers/menu_controler.cpp \
    Main.cpp \
    Models/alive_entity.cpp \
    Models/billblaster.cpp \
    Models/block.cpp \
    Models/blockgrass.cpp \
    Models/bowser.cpp \
    Models/bulletbill.cpp \
    Models/carapace.cpp \
    Models/chateau.cpp \
    Models/checkpoint.cpp \
    Models/entity.cpp \
    Models/flamme.cpp \
    Models/flower.cpp \
    Models/goalpole.cpp \
    Models/goomba.cpp \
    Models/ground.cpp \
    Models/interface_visitable.cpp \
    Models/interface_visitor.cpp \
    Models/koopa.cpp \
    Models/level.cpp \
    Models/lifeup.cpp \
    Models/mario.cpp \
    Models/mushroom.cpp \
    Models/mysteryblock.cpp \
    Models/peach.cpp \
    Models/piece.cpp \
    Models/plante.cpp \
    Models/smoke.cpp \
    Models/spike.cpp \
    Models/star.cpp \
    Models/static_entity.cpp \
    Models/thwomp.cpp \
    Models/trampoline.cpp \
    Models/tuyau.cpp \
    Tools/controls.cpp \
    Views/game_over_view.cpp \
    Views/game_view.cpp \
    Views/game_view_entity.cpp \
    Views/game_view_factory.cpp \
    Views/global_view.cpp \
    Views/menu_view.cpp \
    Views/viewtest.cpp


HEADERS += \
    Controllers/global_views_controller.h \
    Controllers/level_controller.h \
    Controllers/menu_controler.h \
    Models/alive_entity.h \
    Models/billblaster.h \
    Models/block.h \
    Models/blockgrass.h \
    Models/bowser.h \
    Models/bulletbill.h \
    Models/carapace.h \
    Models/chateau.h \
    Models/checkpoint.h \
    Models/entity.h \
    Models/flamme.h \
    Models/flower.h \
    Models/goalpole.h \
    Models/goomba.h \
    Models/ground.h \
    Models/interface_visitable.h \
    Models/interface_visitor.h \
    Models/koopa.h \
    Models/level.h \
    Models/lifeup.h \
    Models/mario.h \
    Models/mushroom.h \
    Models/mysteryblock.h \
    Models/peach.h \
    Models/piece.h \
    Models/plante.h \
    Models/smoke.h \
    Models/spike.h \
    Models/star.h \
    Models/static_entity.h \
    Models/thwomp.h \
    Models/trampoline.h \
    Models/tuyau.h \
    Tools/controls.h \
    Views/game_over_view.h \
    Views/game_view.h \
    Views/game_view_entity.h \
    Views/game_view_factory.h \
    Views/global_view.h \
    Views/menu_view.h \
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

DISTFILES += \
    images/HUD/background.png
