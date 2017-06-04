#pragma once
#include "2048_GameModel_xplat_cpp_cmake/SW2048Game.h"

class CLIViewController
{
#pragma region Constants
	const char KEYBOARD_ARROW_UP_WIN = 72;
	const char KEYBOARD_ARROW_DOWN_WIN = 80;
	const char KEYBOARD_ARROW_LEFT_WIN = 75;
	const char KEYBOARD_ARROW_RIGHT_WIN = 77;
	const char KEYBOARD_ARROW_UP_MAC = 65;
	const char KEYBOARD_ARROW_DOWN_MAC = 66;
	const char KEYBOARD_ARROW_LEFT_MAC = 68;
	const char KEYBOARD_ARROW_RIGHT_MAC = 67;
	const int ORDER = 4;
#pragma endregion

#pragma region Variables
	SW2048Game* game;
#pragma endregion

#pragma region Methods
	bool parseControl(char key);
	void refresh();
	void showScore();
	void showBoard();
	void showResult(bool win);
#pragma endregion

public:
#pragma region Methods
	void start();
#pragma endregion

#pragma region Constructor & Destructor
	CLIViewController();
	~CLIViewController();
#pragma endregion
};

