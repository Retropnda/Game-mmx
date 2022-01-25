#include "game.h"
#include <SDL/SDL.h>

int main(int argc, char **argv){

 GAME *game;
 game = new GAME();

 game->Init(320,240,"Megaman x");

  while(game->is_runing()){
       game->update();
  }
  game->clean();
  delete game;
  game = 0;
  
return 0;
}