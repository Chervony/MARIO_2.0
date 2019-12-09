#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Map.h"
#include <iostream>
using namespace sf;

float offsetX = 0, offsetY = 0;

extern bool GAME_OVER;
extern bool restart;
extern bool WIN;

class Mario {

public:

	float dx, dy;
	FloatRect rect;
	bool onGround;
	Sprite sprite;
	float currentFrame;
	int score;
	int health;



	Mario(Texture& image)
	{
		//Sounds---------------------------------------------

		//---------------------------------------------------
		sprite.setTexture(image);
		rect = FloatRect(100, 180, 16, 16);
		score = 0; health = 3;
		dx = dy = 0.1;
		currentFrame = 0;
	}


	void update(float time)
	{



		rect.left += dx * time;
		Collision(0);


		if (!onGround) dy = dy + 0.0005 * time;
		rect.top += dy * time;
		onGround = false;
		Collision(1);


		currentFrame += time * 0.005;
		if (currentFrame > 3) currentFrame -= 3;


		if (dx > 0) sprite.setTextureRect(IntRect(112 + 31 * int(currentFrame), 144, 16, 16));
		if (dx < 0) sprite.setTextureRect(IntRect(112 + 31 * int(currentFrame) + 16, 144, -16, 16));


		sprite.setPosition(rect.left - offsetX, rect.top - offsetY);

		dx = 0;
	}


	void Collision(int num)
	{
		for (int i = rect.top / 16; i < (rect.top + rect.height) / 16; i++) {
			for (int j = rect.left / 16; j < (rect.left + rect.width) / 16; j++)
			{
				std::cout << i << " " << j << std::endl;
				if ((TileMap[i][j] == 'P') || (TileMap[i][j] == 'k') || (TileMap[i][j] == '0') || (TileMap[i][j] == 'r') || (TileMap[i][j] == 't') || (TileMap[i][j] == 'B') || (TileMap[i][j] == 'c') || (TileMap[i][j] == 'u') || (TileMap[i][j] == 'L'))
				{
					if (dy > 0 && num == 1)
					{
						rect.top = i * 16 - rect.height;  dy = 0;   onGround = true;
					}
					if (dy < 0 && num == 1)
					{
						rect.top = i * 16 + 16;   dy = 0;
					}
					if (dx > 0 && num == 0)
					{
						rect.left = j * 16 - rect.width;
					}
					if (dx < 0 && num == 0)
					{
						rect.left = j * 16 + 16;
					}
				}

				if (TileMap[i][j] == 'c')
				{
					if (dy == (float)0 && !onGround)
					{
						TileMap[i][j] = 'u'; score += 10;
					}
				}

				if (TileMap[i][j] == 'W') {
					WIN = true;
				}

				if (TileMap[i][j] == 'K') {
					if (health > 0) {
						health -= 1;
						offsetX = 0;
						offsetY = 0;
						rect = FloatRect(100, 180, 16, 16);
					}
					else {
						GAME_OVER = true;
						restart = true;
		
					}
				}

			}//second for
		}//firts for
	}

};



class ENEMY
{

public:
	float dx, dy;
	FloatRect rect;
	Sprite sprite;
	float currentFrame;
	bool life;


	void set(Texture& image, int x, int y)
	{
		sprite.setTexture(image);
		rect = FloatRect(x, y, 16, 16);

		dx = 0.05;
		currentFrame = 0;
		life = true;
	}

	void update(float time)
	{
		rect.left += dx * time;

		Collision();


		currentFrame += time * 0.005;
		if (currentFrame > 2) currentFrame -= 2;

		sprite.setTextureRect(IntRect(18 * int(currentFrame), 0, 16, 16));
		if (!life) sprite.setTextureRect(IntRect(58, 0, 16, 16));


		sprite.setPosition(rect.left - offsetX, rect.top - offsetY);

	}


	void Collision()
	{

		for (int i = rect.top / 16; i < (rect.top + rect.height) / 16; i++)
			for (int j = rect.left / 16; j < (rect.left + rect.width) / 16; j++)
				if ((TileMap[i][j] == 'P') || (TileMap[i][j] == '0') || (TileMap[i][j] == 's') || (TileMap[i][j] == 'L'))
				{
					if (dx > 0)
					{
						rect.left = j * 16 - rect.width; dx *= -1;
					}
					else if (dx < 0)
					{
						rect.left = j * 16 + 16;  dx *= -1;
					}

				}
	}

};

class SecondEnemy :public ENEMY {
public:


	void set(Texture& image, int x, int y) { ENEMY::set(image, x, y); }

	void update(float time)
	{
		rect.left += dx * time;

		Collision();


		currentFrame += time * 0.005;
		if (currentFrame > 2) currentFrame -= 2;

		if (dx > 0) sprite.setTextureRect(IntRect(63 + 30 * int(currentFrame), 298, 16, 23));
		if (dx < 0) sprite.setTextureRect(IntRect(63 + 30 * int(currentFrame) + 16, 298, -16, 23));

		if (!life) { sprite.setTextureRect(IntRect(128, 298, 16, 23)); }


		sprite.setPosition(rect.left - offsetX, rect.top - offsetY);

	}


	void Collision()
	{
		ENEMY::Collision();
	}
};