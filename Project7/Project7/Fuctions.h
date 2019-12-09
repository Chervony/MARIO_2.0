#pragma once
extern bool GAME_OVER;
extern bool restart;

void CheckRec(Mario& mario) {
	std::fstream file("record.txt", std::ios::in | std::ios::out);
	int temp;
	if (file.is_open()) {
		file >> temp;
		if (temp < mario.score) {
			std::fstream file("record.txt", std::ios::in | std::ios::out | std::ios::trunc);
			file << mario.score;
		}
	}
}

void intersects(Mario& mario, ENEMY& en1) {
	if (mario.rect.intersects(en1.rect))
	{
		if (en1.life) {

			if (mario.dy > 0) { en1.dx = 0; mario.dy = -0.2; en1.life = false; mario.score += 100;  }

			else {
				mario.health -= 1;
				offsetX = 0;
				offsetY = 0;
				mario.rect = FloatRect(100, 180, 16, 16);
				if (mario.health < 0) {
					restart = true;
					GAME_OVER = true;
				}
			};

		}
	}
}

void HUD(Mario& mario, int& gameTime, Text& text, RenderWindow& window) {
	std::ostringstream playerScoreStr;
	playerScoreStr << mario.score;
	text.setString("Score:" + playerScoreStr.str());
	text.setPosition(view.getCenter().x - 500, view.getCenter().y - 500);
	window.draw(text);

	std::ostringstream playerHealth;
	playerHealth << mario.health;
	text.setString("Lifes:" + playerHealth.str());
	text.setPosition(view.getCenter().x - 390, view.getCenter().y - 500);
	window.draw(text);
	window.draw(mario.sprite);//выводим спрайт на экран

	std::ostringstream playerTime;
	playerTime << gameTime;
	text.setString("Time:" + playerTime.str());
	text.setPosition(view.getCenter().x - 290, view.getCenter().y - 500);
	window.draw(text);
}

