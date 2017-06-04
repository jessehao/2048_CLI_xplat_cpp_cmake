#include "CLIViewController.h"
#include "2048_GameModel_xplat_cpp_cmake/Vector2.h"
#include "xplatform/XPlatform.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>

void CLIViewController::start() {
	game->restart();
	while (true) {
		refresh();
		while(!parseControl(xplt_getch()));
	}
}

void CLIViewController::refresh() {
	xplt_clrscr();
	if (game->isPlaying())
		showBoard();
	else
		showResult(game->isWin());
}

bool CLIViewController::parseControl(char key)
{
	if (key == CLIViewController::KEYBOARD_ARROW_UP_WIN
	 || key == CLIViewController::KEYBOARD_ARROW_UP_MAC
	 || key == 'w' || key == 'W')
		game->move(Vector2::DOWN);
	else if (key == CLIViewController::KEYBOARD_ARROW_DOWN_WIN
		  || key == CLIViewController::KEYBOARD_ARROW_DOWN_MAC
		  || key == 's' || key == 'S')
		game->move(Vector2::UP);
	else if (key == CLIViewController::KEYBOARD_ARROW_LEFT_WIN
		  || key == CLIViewController::KEYBOARD_ARROW_LEFT_MAC
		  || key == 'a' || key == 'A')
		if (game->isPlaying())
			game->move(Vector2::LEFT);
		else
			game->restart();
	else if (key == CLIViewController::KEYBOARD_ARROW_RIGHT_WIN
		  || key == CLIViewController::KEYBOARD_ARROW_RIGHT_MAC
		  || key == 'd' || key == 'D')
		if (game->isPlaying())
			game->move(Vector2::RIGHT);
		else
			std::exit(EXIT_SUCCESS);
	else
		return false;
	return true;
}

CLIViewController::CLIViewController()
{
	game = new SW2048Game(CLIViewController::ORDER);
}


CLIViewController::~CLIViewController()
{
	delete game;
}

#pragma region Private Methods
void CLIViewController::showScore()
{
	using namespace std;
	cout << "Score: " << game->getScore() << "\tMax Cell:" << game->getMaxCell() << endl;
}

void CLIViewController::showBoard()
{
	using namespace std;
	showScore();
	int cell;
	printf("-----------------------------\n");
	for (int y = 0; y < ORDER; y++) {
		printf("|");
		for (int x = 0; x<4; x++) {
			cell = game->getCell(y, x);
			if (cell == 0) printf("      |");
			else if (cell <= 8) printf("%d     |", cell);
			else if (cell <= 64) printf("%d    |", cell);
			else if (cell <= 512) printf("%d   |", cell);
			else if (cell <= 2048) printf("%d  |", cell);
			else if (cell <= 16384) printf("%d |", cell);
		}
		printf("\n");
		if (y == ORDER - 1)
			printf("-----------------------------\n\n");
		else
			printf("-----------------------------\n");
	}
	printf("Control: Up(W), Down(S), Right(A), Left(D).\n");
}

void CLIViewController::showResult(bool win) {
	using namespace std;
	if (win) {
		cout << "-=Congraduations ! You Win=-";
	}
	else {
		cout << "Game Over";
	}
	cout << endl << endl << endl;
	showScore();
	cout << "Left : Restart" << endl << " Right : Exit" << endl;
}
#pragma endregion

