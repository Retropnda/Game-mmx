#include "game.h"
#include <stdio.h>
#include <string.h>
#include "player.h"

GAME::GAME()
{
	w = 0;
	h = 0;
	screen = NULL;
}

GAME::~GAME()
{
}

bool GAME::Init(int W, int H, const char *text)
{
	w = W;
	h = H;
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) < 0)
	{
		fprintf(stdout, "error: %s\n", SDL_GetError());
		return false;
	}

	screen = SDL_SetVideoMode(w, h, 32, SDL_HWSURFACE);

	if (screen)
	{
		fprintf(stdout, "screen w->%d h->%d\n", w, h);
	}
	else
	{
		fprintf(stdout, "error: %s\n", SDL_GetError());
		return false;
	}

	fprintf(stdout, "%s\n", text);
	runing = true;
    mmx = new PLAYER(100,100);
    mmx->Init();

	return true;
}

void GAME::update()
{
    event();
    mmx->draw(screen);
	SDL_Flip(screen);
    cls();
}

void GAME::clean()
{
	SDL_FreeSurface(screen);
}

void GAME::cls()
{
	memset(screen->pixels, 0, screen->pitch * screen->h);
}

void GAME::event()
{
	SDL_PollEvent(&e);
	switch (e.type)
	{
	case SDL_KEYDOWN:
		if (e.key.keysym.sym == SDLK_SPACE)
		{
			runing = false;
		}
		 break;
	default:
		break;
	}
}