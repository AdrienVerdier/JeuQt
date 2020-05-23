#include "game_view.h"

Game_View::Game_View()
{

}

void Game_View::paint(Entity entity){
    if(entity.getDisplay()){

        //AJout dans la map OU mise à jour
    }
    else{
        //Suprression de la map et désallocation du Game_View_Entity
    }
}
