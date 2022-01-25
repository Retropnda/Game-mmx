#ifndef PLAYER_H_
#define PLAYER_H_

#include "Sprite.h"
#include <SDL/SDL.h>


enum
{
	walk_left,
	walk_right,
	sleep_left,
	sleep_right,
	intro, max_spr
};


class PLAYER
{
  public:
	PLAYER(int x, int y);
	~PLAYER();
	Sprite *spr[max_spr];
	void Init();
    void update();
    void draw(SDL_Surface *s);
  private:
	int x, y;
	int w, h;
	int vidas;
	int nivel_vida;

};


#endif