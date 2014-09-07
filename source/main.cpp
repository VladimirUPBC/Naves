#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include "Game.h"

SDL_Event event;
int done = 0;


int main(int args,char* argv[])
{
	Game *juego = new Game();
	while(!done)
	{
		if(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT) {done = 1;}
		}
		juego ->MotorEstados();

	}
	return 0;

}