#include "player.h"


PLAYER::PLAYER(int x, int y)
{
 this->x=x;
 this->y=y;
}

PLAYER::~PLAYER()
{}

void PLAYER::Init()
{

 spr[walk_right] = new Sprite("GFX/walk.png",8,60);
spr[walk_right]->setTransparency(255,0,255);
 
}

void PLAYER::draw(SDL_Surface *s){
  spr[walk_right]->animate()->draw(s,x,y);
}