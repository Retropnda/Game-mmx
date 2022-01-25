#ifndef GAME_H_
#define GAME_H_

#include <SDL/SDL.h>
#include "player.h"

class GAME
{
  public:
	GAME();
	~GAME();
     bool Init(int W, int H, const char *text);
     void update();
     bool is_runing(){return runing;}
     void event();
     void clean();
     void cls();
      PLAYER *mmx;

  private:
	int w, h;
	bool runing;
	SDL_Surface *screen;
	SDL_Event e;
  };


#endif