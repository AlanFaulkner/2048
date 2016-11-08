#pragma once
#include <SDL.h>

class Graphics
{
public:
	Graphics();
	~Graphics();

	//The window we'll be rendering to
	SDL_Window *Main_window = NULL;

	//This is the main renenderer
	SDL_Renderer *Main_render = NULL;

	//this is the surface used for loading
	SDL_Surface *loadSurface = NULL;

	//this is the background image
	SDL_Texture *background_text = NULL;

	//this is for a tile
	SDL_Texture *tile = NULL;

	
	void initBoard();
	void updateBoard();
	void placeTile(int value, int x_pos, int y_pos);
	void draw_Board();
	void draw_Tiles();
	void exit();
};

