#pragma once
#include "PlayerAndEnemy.h"



void InitEnemy(ENEMY& en1, ENEMY& en2) {

	Texture tileSetEn;
	tileSetEn.loadFromFile("Images/Mario_Tileset.png");

	en1.set(tileSetEn, 30 * 16, 13 * 16);
	en2.set(tileSetEn, 50 * 16, 13 * 16);
}

void UpdateEnemy(ENEMY& en1, ENEMY& en2, float time) {
	en1.update(time);
	en2.update(time);
}


void CheckEnemyRect(ENEMY& en1, ENEMY& en2, Mario& mar, Sound& kick) {
	if (mar.rect.intersects(en1.rect))
	{
		if (en1.life) {

			if (mar.dy > 0) { en1.dx = 0; mar.dy = -0.2; en1.life = false; mar.score += 100; kick.play(); }

			else {
				mar.health -= 1;
				offsetX = 0;
				offsetY = 0;
				mar.rect = FloatRect(100, 180, 16, 16);
			};

		}
	}

	if (en2.rect.intersects(en2.rect))
	{
		if (en2.life) {

			if (mar.dy > 0) { en2.dx = 0; mar.dy = -0.2; en2.life = false; mar.score += 100; kick.play(); }

			else {
				mar.health -= 1;
				offsetX = 0;
				offsetY = 0;
				mar.rect = FloatRect(100, 180, 16, 16);
			};

		}
	}
}

void DrawEnemy(ENEMY& en1, ENEMY& en2, RenderWindow& window) {
	window.draw(en1.sprite);
	window.draw(en2.sprite);
}