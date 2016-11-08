#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>

enum class GameState { PLAY, EXIT };

class Game
{
public:
	Game();
	~Game();
	void initBoard();
	void mainGame();
	void exit();
	

private:
	GameState _GameState;

	float board[4][4];
	void popBoard();
	void printBoard();
	void printBoard2();
	void checkScore();
	int A;
	int B;
	int C=0;

};

