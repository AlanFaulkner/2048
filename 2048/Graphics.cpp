#include "Graphics.h"
#include <iostream>

Graphics::Graphics()
{
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cout << "SDL could not initialize!" << std::endl;
	}

	//How to open a window - the window object needs to be a pointer
	Main_window = SDL_CreateWindow("2048", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 226, 312, SDL_WINDOW_SHOWN);
	if (Main_window == nullptr) {
		std::cout << "Could not create a SDL window" << std::endl;
	}

	//Create main render
	Main_render = SDL_CreateRenderer(Main_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (Main_render == nullptr) {
		SDL_DestroyWindow(Main_window);
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
	}
}


Graphics::~Graphics()
{
}

void Graphics::draw_Board()
{
	//loads a background texture

	loadSurface = SDL_LoadBMP("Graphics/Board.bmp");
	if (loadSurface == nullptr) {
		SDL_DestroyRenderer(Main_render);
		SDL_DestroyWindow(Main_window);
		std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
	}

	background_text = SDL_CreateTextureFromSurface(Main_render, loadSurface);
	SDL_FreeSurface(loadSurface);
	if (background_text == nullptr) {
		SDL_DestroyRenderer(Main_render);
		SDL_DestroyWindow(Main_window);
		std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
	}

	//First clear the renderer
	SDL_RenderClear(Main_render);
	//Draw the texture
	SDL_RenderCopy(Main_render, background_text, NULL, NULL);
	//Update the screen
	SDL_RenderPresent(Main_render);
	//SDL_Delay(200);
}

void Graphics::updateBoard()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
	}

	SDL_Window *Main_window = SDL_CreateWindow("2048", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 226, 312, SDL_WINDOW_SHOWN);
	if (Main_window == nullptr) {
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
	}

	SDL_Renderer *Main_render = SDL_CreateRenderer(Main_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (Main_render == nullptr) {
		SDL_DestroyWindow(Main_window);
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
	}

//loads a background texture

	SDL_Surface *loadSurface = SDL_LoadBMP("Graphics/Board.bmp");
	if (loadSurface == nullptr) {
		SDL_DestroyRenderer(Main_render);
		SDL_DestroyWindow(Main_window);
		std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
	}

	SDL_Texture *background_text = SDL_CreateTextureFromSurface(Main_render, loadSurface);
	SDL_FreeSurface(loadSurface);
	if (background_text == nullptr) {
		SDL_DestroyRenderer(Main_render);
		SDL_DestroyWindow(Main_window);
		std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
	}

//Load second image - tile


	SDL_Rect offset;
	offset.x = (5 + (55 * 1));
	offset.y = (256 - (55 * 1));
	offset.h = 50;
	offset.w = 50;

	loadSurface = SDL_LoadBMP("Graphics/2.bmp");
	if (loadSurface == nullptr) {
		SDL_DestroyRenderer(Main_render);
		SDL_DestroyWindow(Main_window);
		std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
	}

	tile = SDL_CreateTextureFromSurface(Main_render, loadSurface);
	SDL_FreeSurface(loadSurface);
	if (background_text == nullptr) {
		SDL_DestroyRenderer(Main_render);
		SDL_DestroyWindow(Main_window);
		std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
	}

	std::cout<<"first image"<<std::endl;
	//First clear the renderer
	//SDL_RenderClear(Main_render);
	//Draw the texture
	SDL_RenderCopy(Main_render, background_text, NULL, NULL);
	//Update the screen
	SDL_RenderPresent(Main_render);
	SDL_Delay(2000);
	std::cout << "second image" << std::endl;
	//First clear the renderer
	SDL_RenderClear(Main_render);
	//Draw the texture
	SDL_RenderCopy(Main_render, background_text, NULL, NULL);
	SDL_RenderCopy(Main_render, tile, NULL, &offset);
	//Update the screen
	SDL_RenderPresent(Main_render);
	SDL_Delay(2000);

	std::cout << "end of inital texture" << std::endl;

}

void Graphics::placeTile(int value, int x_pos, int y_pos)
{
	//loads a background texture

	loadSurface = SDL_LoadBMP("Graphics/Board.bmp");
	if (loadSurface == nullptr) {
		SDL_DestroyRenderer(Main_render);
		SDL_DestroyWindow(Main_window);
		std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
	}

	background_text = SDL_CreateTextureFromSurface(Main_render, loadSurface);
	SDL_FreeSurface(loadSurface);
	if (background_text == nullptr) {
		SDL_DestroyRenderer(Main_render);
		SDL_DestroyWindow(Main_window);
		std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
	}

	//load tile

	SDL_Rect offset;
	offset.x = (5 + (55 * x_pos));
	offset.y = (256 - (55 * y_pos));
	offset.w = 50;
	offset.h = 50;

	switch(value) {
		case (2) :
			////Load tile image
			loadSurface = SDL_LoadBMP("Graphics/2.bmp");
			if (loadSurface == NULL)
			{
				printf("Unable to load image %s! SDL Error: %s\n", "\Graphics\2.bmp", SDL_GetError());
			}
			break;
		case (4) :
			////Load tile image
			loadSurface = SDL_LoadBMP("Graphics/4.bmp");
			if (loadSurface == NULL)
			{
				printf("Unable to load image %s! SDL Error: %s\n", "\Graphics\4.bmp", SDL_GetError());
			}
			break;
		case (8) :
			////Load tile image
			loadSurface = SDL_LoadBMP("Graphics/8.bmp");
			if (loadSurface == NULL)
			{
				printf("Unable to load image %s! SDL Error: %s\n", "\Graphics\8.bmp", SDL_GetError());
			}
			break;
		case (16) :
			////Load tile image
			loadSurface = SDL_LoadBMP("Graphics/16.bmp");
			if (loadSurface == NULL)
			{
				printf("Unable to load image %s! SDL Error: %s\n", "\Graphics\16.bmp", SDL_GetError());
			}
			break;
		case (32) :
			////Load tile image
			loadSurface = SDL_LoadBMP("Graphics/32.bmp");
			if (loadSurface == NULL)
			{
				printf("Unable to load image %s! SDL Error: %s\n", "\Graphics\32.bmp", SDL_GetError());
			}
			break;
		case (64) :
			////Load tile image
			loadSurface = SDL_LoadBMP("Graphics/64.bmp");
			if (loadSurface == NULL)
			{
				printf("Unable to load image %s! SDL Error: %s\n", "\Graphics\64.bmp", SDL_GetError());
			}
			break;
		case (128) :
			////Load tile image
			loadSurface = SDL_LoadBMP("Graphics/128.bmp");
			if (loadSurface == NULL)
			{
				printf("Unable to load image %s! SDL Error: %s\n", "\Graphics\128.bmp", SDL_GetError());
			}
			break;
		case (256) :
			////Load tile image
			loadSurface = SDL_LoadBMP("Graphics/256.bmp");
			if (loadSurface == NULL)
			{
				printf("Unable to load image %s! SDL Error: %s\n", "\Graphics\256.bmp", SDL_GetError());
			}
			break;
		case (512) :
			////Load tile image
			loadSurface = SDL_LoadBMP("Graphics/512.bmp");
			/*if (loadSurface == NULL)
			{
				printf("Unable to load image %s! SDL Error: %s\n", "\Graphics\512.bmp", SDL_GetError());
			}*/
			break;
		case (1024) :
			////Load tile image
			loadSurface = SDL_LoadBMP("Graphics/1024.bmp");
			if (loadSurface == NULL)
			{
				printf("Unable to load image %s! SDL Error: %s\n", "\Graphics\1024.bmp", SDL_GetError());
			}
			break;
		case (2048) :
			////Load tile image
			loadSurface = SDL_LoadBMP("Graphics/2048.bmp");
			if (loadSurface == NULL)
			{
				printf("Unable to load image %s! SDL Error: %s\n", "\Graphics\2048.bmp", SDL_GetError());
			}
			break;

	}

	tile = SDL_CreateTextureFromSurface(Main_render, loadSurface);
	SDL_FreeSurface(loadSurface);
	if (background_text == nullptr) {
		SDL_DestroyRenderer(Main_render);
		SDL_DestroyWindow(Main_window);
		std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
	}

	SDL_RenderCopy(Main_render, tile, NULL, &offset);

}


void Graphics::draw_Tiles()
{
	//Update the screen
	SDL_RenderPresent(Main_render);
	SDL_Delay(2000);
}

void Graphics::exit()
{
	//Destroy window
	SDL_DestroyWindow(Main_window);

	//Quit SDL subsystems
	SDL_Quit();
}
