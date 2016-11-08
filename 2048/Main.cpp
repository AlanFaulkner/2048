#include <iostream>
#include <SDL.h>
// libs for random number generator
#include <cstdlib>
#include <ctime>
#include <conio.h>

//game related things
enum class GameState { PLAY, EXIT };
GameState _GameState;

//pointers related to graphics window
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

//board parameters
int Board[4][4];
int A = 0;
int B = 0;


void fill_Board_0()
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			Board[i][j] = 0;
		}
	}
}

void print_board_to_console()
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			std::cout << Board[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void place_Random_tile()
{
	//Puts a 2 at a random unoccupied position on the board
	srand(time(NULL));
	A = rand() % 4;
	B = rand() % 4;

	while (Board[A][B] != 0) {
		srand(clock());
		A = rand() % 4;
		B = rand() % 4;
	}

	Board[A][B] = 2;
}

GameState check_score()
{
	std::cout << "check score run" << std::endl;
	int a = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (Board[i][j] == 2048) {
				//system("cls");
				std::cout << "You win!" << std::endl;

				//loads a background texture

				loadSurface = SDL_LoadBMP("Graphics/Win.bmp");
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
				SDL_Delay(2000);
				_GameState = GameState::EXIT;
				return _GameState;

			}
			else if (Board[i][j] == 0)
				a++;
		}
	}

	if (a == 0) {
		//system("cls");
		std::cout << "Sorry You Loose!" << std::endl;

		//loads a background texture

		loadSurface = SDL_LoadBMP("Graphics/Loose.bmp");
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
		SDL_Delay(2000);
		_GameState = GameState::EXIT;
		return _GameState;
	}
}

//drawing and up dating the board

void updates_MainRender_with_tiles()
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

	int C = 0;
	for (int i = 0; i<4; i++) {
		for (int j = 0; j<4; j++) {
			if (Board[i][j]>0) {
				C = Board[i][j];
				
				//load tile
				SDL_Rect offset;
				offset.x = (5 + (55 * j));
				offset.y = (256 - (55 * (3-i)));
				offset.w = 50;
				offset.h = 50;

				switch (C) {
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
		}
	}
	//Update the screen
	SDL_RenderPresent(Main_render);
}

void reDraw_Board()
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
}

//initalise SDL window and draw background


int main (int argc, char **argv)
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

fill_Board_0();
place_Random_tile();
updates_MainRender_with_tiles();

//move tiles

while (_GameState != GameState::EXIT) {

	SDL_Event evnt;
	while (SDL_PollEvent(&evnt)) {
		switch (evnt.type) {
		case SDL_QUIT:
			_GameState = GameState::EXIT;
			std::cout << "close button" << std::endl;
			break;

		case SDL_KEYDOWN:

			switch (evnt.key.keysym.sym)
			{

			case SDLK_UP:
				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < 4; j++) {
						for (int k = 0; k < 3; k++) {

							if (Board[k][j] == 0) {
								Board[k][j] = Board[k + 1][j];
								Board[k + 1][j] = 0;
							}
							else if (Board[k + 1][j] == Board[k][j]) {
								Board[k][j] += Board[k + 1][j];
								Board[k + 1][j] = 0;
							}
						}
					}
				}
				std::cout << std::endl<<"Up" << std::endl;
				place_Random_tile();
				print_board_to_console();
				check_score();
				if (_GameState == GameState::EXIT)
					break;
				else updates_MainRender_with_tiles();
				break;

			case SDLK_DOWN:
				for (int i = 0; i<4; i++) {
					for (int j = 0; j<4; j++) {
						for (int k = 3; k > 0; k--) {

							if (Board[k][j] == 0) {
								Board[k][j] = Board[k - 1][j];
								Board[k - 1][j] = 0;
							}
							else if (Board[k - 1][j] == Board[k][j]) {
								Board[k][j] += Board[k - 1][j];
								Board[k - 1][j] = 0;
							}
						}
					}
				}

				std::cout << std::endl <<"down" << std::endl;
				place_Random_tile();
				print_board_to_console();
				check_score();
				if (_GameState == GameState::EXIT)
					break;
				else updates_MainRender_with_tiles();
				break;

			case SDLK_LEFT:

				for (int i = 0; i<4; i++) {
					for (int j = 0; j<3; j++) {
						for (int k = 0; k<3; k++) {

							if (Board[i][k] == 0) {
								Board[i][k] = Board[i][k + 1];
								Board[i][k + 1] = 0;
							}
							else if (Board[i][k + 1] == Board[i][k]) {
								Board[i][k] += Board[i][k + 1];
								Board[i][k + 1] = 0;
							}
						}
					}
				}

				std::cout << std::endl<< "left" << std::endl;
				place_Random_tile();
				print_board_to_console();
				check_score();
				if (_GameState == GameState::EXIT)
					break;
				else updates_MainRender_with_tiles();
				break;

			case SDLK_RIGHT:

				for (int i = 0; i<4; i++) {
					for (int j = 3; j >= 0; j--) {
						for (int k = 3; k>0; k--) {

							if (Board[i][k] == 0) {
								Board[i][k] = Board[i][k - 1];
								Board[i][k - 1] = 0;
							}
							else if (Board[i][k - 1] == Board[i][k]) {
								Board[i][k] += Board[i][k - 1];
								Board[i][k - 1] = 0;
							}
						}
					}
				}
				std::cout << std::endl << "right" << std::endl;
				place_Random_tile();
				check_score();
				print_board_to_console();
				if (_GameState == GameState::EXIT)
					break;
				else updates_MainRender_with_tiles();
				break;

			case SDLK_q:
				_GameState = GameState::EXIT;
				std::cout << "q" << std::endl;
				break;

			default:
				if (_GameState == GameState::EXIT);
				break;
			}
			break;
		}

	}
}
return 1;
}