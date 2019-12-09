#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>
#include "View.h"
#include "PlayerAndEnemy.h"
#include "menu.h"
#include "EnemyInit.h"
#include <iostream>
#include <fstream>
#include "Fuctions.h"

extern bool GAME_OVER;
extern bool WIN;

bool StartGame() {
	RenderWindow window(VideoMode(600, 400), "Mario");
	Font font;
	font.loadFromFile("17869.ttf");

	Image icon;
	if (!icon.loadFromFile("Images/icon.png"))
	{
		return 1;
	}
	window.setIcon(16, 16, icon.getPixelsPtr());

	Text text("", font, 10);
	text.setFillColor(Color::White);


	Clock gameTimeClock;
	int gameTime = 0;


	Texture tileSet;
	tileSet.loadFromFile("Images/Mario_Tileset.png");


	Mario mario(tileSet);
	//ENEMY------------------------------
	ENEMY enemy[9];
	enemy[0].set(tileSet, 30 * 16, 13 * 16);
	enemy[1].set(tileSet, 50 * 16, 13 * 16);
	enemy[2].set(tileSet, 60 * 16, 13 * 16);
	enemy[3].set(tileSet, 63 * 16, 13 * 16);
	enemy[4].set(tileSet, 90 * 16, 13 * 16);
	enemy[5].set(tileSet, 93 * 16, 6 * 16);
	enemy[6].set(tileSet, 105 * 16, 13 * 16);
	enemy[7].set(tileSet, 120 * 16, 13 * 16);
	SecondEnemy che;
	che.set(tileSet, 110 * 16, 201);
	/*en4.set(tileSet, 65 * 16, 13 * 16);*/
	//-----------------------------------

	/*ENEMY  enemy2;
	enemy2.set(tileSet, 0, 0);*/

	Sprite tile(tileSet);

	Clock clock;

	menu(window, WIN);

	while (window.isOpen())
	{
		//std::cout << offsetX << " " << offsetY << std::endl;
		gameTime = gameTimeClock.getElapsedTime().asSeconds();
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();

		time = time / 600;  // çäåñü ðåãóëèðóåì ñêîðîñòü èãðû

		if (time > 20) time = 20;

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) {
				window.close();
				restart = false;
				return false;
			}
		}


		if (Keyboard::isKeyPressed(Keyboard::Left))    mario.dx = -0.1;

		if (Keyboard::isKeyPressed(Keyboard::Right))    mario.dx = 0.1;

		if (Keyboard::isKeyPressed(Keyboard::Up))	if (mario.onGround) { mario.dy = -0.27; mario.onGround = false;   }


		enemy[0].update(time);
		enemy[1].update(time);
		enemy[2].update(time);
		enemy[3].update(time);
		enemy[4].update(time);
		enemy[5].update(time);
		enemy[6].update(time);
		enemy[7].update(time);
		che.update(time);
		mario.update(time);


		intersects(mario, enemy[0]);
		intersects(mario, enemy[1]);
		intersects(mario, enemy[2]);
		intersects(mario, enemy[3]);
		intersects(mario, enemy[4]);
		intersects(mario, enemy[5]);
		intersects(mario, enemy[6]);
		intersects(mario, enemy[7]);
		intersects(mario, che);


		if (mario.rect.left > 200) offsetX = mario.rect.left - 200;           //ñìåùåíèå




		window.clear(Color(107, 140, 255));

		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++)
			{
				if (TileMap[i][j] == 'P')  tile.setTextureRect(IntRect(143 - 16 * 3, 112, 16, 16));

				if (TileMap[i][j] == 'k')  tile.setTextureRect(IntRect(143, 112, 16, 16));

				if (TileMap[i][j] == 'c')  tile.setTextureRect(IntRect(143 - 16, 112, 16, 16));

				if (TileMap[i][j] == 't')  tile.setTextureRect(IntRect(0, 47, 32, 95 - 47));

				if (TileMap[i][j] == 'g')  tile.setTextureRect(IntRect(0, 16 * 9 - 5, 3 * 16, 16 * 2 + 5));

				if (TileMap[i][j] == 'G')  tile.setTextureRect(IntRect(145, 222, 222 - 145, 255 - 222));

				if (TileMap[i][j] == 'd')  tile.setTextureRect(IntRect(0, 106, 74, 127 - 106));

				if (TileMap[i][j] == 'w')  tile.setTextureRect(IntRect(99, 224, 140 - 99, 255 - 224));

				if (TileMap[i][j] == 'r')  tile.setTextureRect(IntRect(143 - 32, 112, 16, 16));

				if (TileMap[i][j] == 'u')  tile.setTextureRect(IntRect(143 - 16, 112 + 16, 16, 16));

				if (TileMap[i][j] == 'E')  tile.setTextureRect(IntRect(96, 6, 106, 106));

				if (TileMap[i][j] == 'B')  tile.setTextureRect(IntRect(0, 298, 32, 91));

				if (TileMap[i][j] == 'L')  tile.setTextureRect(IntRect(112, 112, 16, 16));

				if (TileMap[i][j] == 'F')  tile.setTextureRect(IntRect(299, 47, 29, 119));



				if ((TileMap[i][j] == ' ') || (TileMap[i][j] == '0') || TileMap[i][j] == 'K' || TileMap[i][j] == 's' || TileMap[i][j] == 'W') continue;

				tile.setPosition(j * 16 - offsetX, i * 16 - offsetY);
				window.draw(tile);
			}

		HUD(mario, gameTime, text, window);

		window.draw(enemy[0].sprite);
		window.draw(enemy[1].sprite);
		window.draw(enemy[2].sprite);
		window.draw(enemy[3].sprite);
		window.draw(enemy[4].sprite);
		window.draw(enemy[5].sprite);
		window.draw(enemy[6].sprite);
		window.draw(enemy[7].sprite);
		window.draw(che.sprite);


		window.display();

		if (WIN == true) {
			CheckRec(mario);
			return true;
		}
		if (GAME_OVER == true) {
			restart = true;
			GAME_OVER = false;
			CheckRec(mario);
			return false;
		}
		if (mario.health < 0) {
			restart = true;
			CheckRec(mario);
			return true;
			mario.health = 3;
		}
	}



	CheckRec(mario);

}
