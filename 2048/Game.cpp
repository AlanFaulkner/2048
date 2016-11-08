#include "Game.h"
#include <iostream>
#include "Graphics.h"


Game::Game()
{
}


Game::~Game()
{
}

void Game::initBoard()
{
	//Sets the board array to 0
	for (int i = 0; i<4; i++) {
		for (int j = 0; j<4; j++) {
			board[i][j] = 0;
		}
	}

	return;
}

void Game::popBoard()
{
		//Puts a 2 at a random unoccupied position on the board
		srand(time(NULL));
		A = rand() % 5;
		B = rand() % 5;
		while (board[A][B] != 0) {
			srand(clock());
			A = rand() % 5;
			B = rand() % 5;
		}
	
		board[A][B] = 2;
}

void Game::printBoard()
{
	Graphics Draw;
	Draw.draw_Board();
	C = 0;
	for (int i = 0; i<4; i++) {
		for (int j = 0; j<4; j++) {
			std::cout << board[i][j] << " ";
			if (board[i][j]>0) {
				C = board[i][j];
				Draw.placeTile(C, j, (3 - i));
			}
		}
		std::cout << std::endl;
	}
	std::cout << "C in print function= " << C << std::endl;
	Draw.draw_Tiles();
}

void Game::exit()
{
	Graphics clearScreen;
	clearScreen.exit();
}

void Game::mainGame()
{
	while (_GameState != GameState::EXIT) {

		SDL_Event evnt;
		while (SDL_PollEvent(&evnt)) {
			switch (evnt.type){
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

								if (board[k][j] == 0) {
									board[k][j] = board[k + 1][j];
									board[k + 1][j] = 0;
								}
								else if (board[k + 1][j] == board[k][j]) {
									board[k][j] += board[k + 1][j];
									board[k + 1][j] = 0;
								}
							}
						}
					}
					std::cout << "Up" << std::endl;
					Game::popBoard();
					Game::printBoard();
					Game::checkScore();
					break;

				case SDLK_DOWN:
					for (int i = 0; i<4; i++) {
						for (int j = 0; j<4; j++) {
							for (int k = 3; k >= 0; k--) {

								if (board[k][j] == 0) {
									board[k][j] = board[k - 1][j];
									board[k - 1][j] = 0;
								}
								else if (board[k - 1][j] == board[k][j]) {
									board[k][j] += board[k - 1][j];
									board[k - 1][j] = 0;
								}
							}
						}
					}

					std::cout << "down" << std::endl;
					Game::popBoard();
					Game::printBoard();
					Game::checkScore();
					break;

				case SDLK_LEFT:

					for (int i = 0; i<4; i++) {
						for (int j = 0; j<3; j++) {
							for (int k = 0; k<3; k++) {

								if (board[i][k] == 0) {
									board[i][k] = board[i][k + 1];
									board[i][k + 1] = 0;
								}
								else if (board[i][k + 1] == board[i][k]) {
									board[i][k] += board[i][k + 1];
									board[i][k + 1] = 0;
								}
							}
						}
					}

					std::cout << "left" << std::endl;
					Game::popBoard();
					Game::printBoard();
					Game::checkScore();
					break;

				case SDLK_RIGHT:

					for (int i = 0; i<4; i++) {
						for (int j = 3; j >= 0; j--) {
							for (int k = 3; k>0; k--) {

								if (board[i][k] == 0) {
									board[i][k] = board[i][k - 1];
									board[i][k - 1] = 0;
								}
								else if (board[i][k - 1] == board[i][k]) {
									board[i][k] += board[i][k - 1];
									board[i][k - 1] = 0;
								}
							}
						}
					}
					std::cout << "right" << std::endl;
					Game::popBoard();
					Game::printBoard();
					Game::checkScore();
					break;

				case SDLK_q:
					_GameState = GameState::EXIT;
					std::cout << "q" << std::endl;
					break;

				default:
					break;
				}
				break;
			}

		}
	}
}

void Game::checkScore()
{
	int a = 0;
	for (int i = 0; i<5; i++) {
		for (int j = 0; j<5; j++) {
			if (board[i][j] == 2048) {
				//system("cls");
				std::cout << "You win!" << std::endl;
			}
			else if (board[i][j] == 0)
				a++;
		}
	}

	if (a == 0) {
		//system("cls");
		std::cout << "Sorry You Loose!" << std::endl;
	}
}