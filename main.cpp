#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>

#define WIDTH 420
#define HEIGHT 360
#define BPP 24

SDL_Surface *image, *screen;
SDL_Rect dest;
SDL_Event event;
int done = 0;
Uint8 *keys;
int background;
int HNave,WNave ;
struct nave{
    int x,y;
} minave;

int main(int args,char* argv[])
{
	atexit(SDL_Quit);

if(SDL_Init(SDL_INIT_VIDEO) < 0)
{
    printf("No se ha podido iniciar SDL: %s\n", SDL_GetError());
    exit(1);
}

	screen = SDL_SetVideoMode(WIDTH, HEIGHT, BPP, SDL_HWSURFACE);

if(screen == NULL)
{
    printf("No se ha podido establecer el modo de vídeo: %s\n", SDL_GetError());
    exit(1);
}
	image = SDL_LoadBMP("Nave.bmp");
	//Cambiar Fondo SDL_SetColorKey -- Sets the color key (transparent pixel) in a blittable surface and RLE acceleration.
	SDL_SetColorKey(image, SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB(image -> format, 255, 0, 0));

	HNave = image ->h;
	WNave = image ->w;
	
	if(image == NULL)
	{
		printf("No se ha podido cargar la imagen: %s\n",SDL_GetError());
	}



minave.x = 50;
minave.y = 10;

dest.x = minave.x;
dest.y = minave.y;
dest.w = image -> w;
dest.h = image -> h;

SDL_BlitSurface(image, NULL, screen, &dest);
SDL_Flip(screen);
SDL_FreeSurface(image); 

background = SDL_MapRGB(screen->format, 0,0,0);

while(!done)
{
	
	if(SDL_PollEvent(&event))
	{
		if(event.type == SDL_QUIT) {done = 1;}
		
	}
	SDL_FillRect(screen, &dest, background);
	
	keys = SDL_GetKeyState(NULL);
	
	if(keys[SDLK_UP] && minave.y > 0) {minave.y = minave.y - (1);}
	if(keys[SDLK_DOWN] && minave.y < HEIGHT - HNave) {minave.y = minave.y + (1);}
	if(keys[SDLK_LEFT] && minave.x > 0) {minave.x = minave.x - (1);}
	if(keys[SDLK_RIGHT] && minave.x <  WIDTH - HNave) {minave.x = minave.x + (1);}

	image = SDL_LoadBMP("Nave.bmp");
	//Cambiar Fondo
	SDL_SetColorKey(image, SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB(image -> format, 255, 0, 0));
	dest.x= minave.x;
	dest.y= minave.y;
	dest.w=image->w;
	dest.h=image->h;
	SDL_BlitSurface(image,NULL,screen,&dest);
	SDL_FreeSurface(image);
	SDL_Flip(screen);
}
	return 0;
	
}