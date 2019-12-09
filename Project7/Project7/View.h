#pragma once
#include <SFML/Graphics.hpp>


sf::View view;


sf::View setplayercoordforview(float x, float y) {
	float tempx = x; float tempy = y;

	if (x < 650) { tempx = 650; }
	if (y < 240) { tempy = 240; }


	view.setCenter(tempx, tempy);
	return view;
}