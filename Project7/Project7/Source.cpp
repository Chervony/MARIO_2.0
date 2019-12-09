#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>
#include "View.h"
#include "PlayerAndEnemy.h"
#include "menu.h"
#include "EnemyInit.h"
#include <iostream>
#include <fstream>
#include "StartGame.h";
#include "Fuctions.h"

using namespace sf;


extern float offsetX, offsetY;

bool WIN = false, GAME_OVER = false, restart = false;

extern bool isExit;



void gameRunning() {
	if (StartGame() && !isExit) { gameRunning(); }
}

int main()
{
	restart = true;
	while (restart) {
		restart = false;

		gameRunning();
	}

	return 0;
}



