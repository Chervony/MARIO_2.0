#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <fstream>

using namespace sf;

bool isExit = false;

void menu(RenderWindow& window, bool isWin) {
	std::fstream file("record.txt", std::ios::in | std::ios::out);
	//Texture---------------------------------------------|
	Texture menuTexture1, aboutTexture, wintex;			//|
	menuTexture1.loadFromFile("Images/MM.png");			//|
	aboutTexture.loadFromFile("Images/about.png");
	wintex.loadFromFile("Images/win.png");			//|
	//|
	//----------------------------------------------------|

	//Sprite---------------------------------------------|
	Sprite menu1(menuTexture1);					       //|
	Sprite about(aboutTexture);						   //|
	Sprite wins(wintex);							   //|
	//---------------------------------------------------|

	bool isMenu = 1;
	int menuNum = 0;
	menu1.setPosition(0, 0);

	//FONT--------------------------------|
	Font font;					        //|
	font.loadFromFile("17869.ttf");		//|
	//------------------------------------|
	int rec = 0;
	if (file.is_open()) {
		file >> rec;
	}
	else rec = 0;
	//TEXT-----------------------------------------|
	//Record									 //|
	Text Record("", font, 8);					 //|
	Record.setFillColor(Color::White);			 //|
	std::ostringstream recor;					 //|
	recor << rec;								 //|
	Record.setString("Record:" + recor.str());   //|
	Record.setPosition(125, 200);				 //|
												 //|
	//START										 //|
	Text Start("START GAME", font, 20);			 //|
	Start.setFillColor(Color::White);			 //|
	Start.setPosition(200, 230);				 //|
	//ABOUT										 //|
	Text About("ABOUT", font, 20);			     //|
	About.setFillColor(Color::White);			 //|
	About.setPosition(245, 260);				 //|
	//EXIT										 //|
	Text Exit("EXIT", font, 20);			     //|
	Exit.setFillColor(Color::White);			 //|
	Exit.setPosition(260, 290);					 //|
	//AUTOR										 //|
	Text Aut("Game by Egor Chervony", font, 8);  //|
	Aut.setFillColor(Color::White);				 //|
	Aut.setPosition(300, 200);					 //|
	//---------------------------------------------|

	if (isWin == false) {


		//---------------------------------------------------------------------лемч-----------------------------------------------------------------------------------------------
		while (isMenu)																																							//|
		{																																										//|
			menu1.setColor(Color::White);																																		//|
			menuNum = 0;																																						//|
			window.clear();																																						//|
																																												//|
			if (IntRect(200, 230, 210, 20).contains(Mouse::getPosition(window))) { Start.setFillColor(Color::Black);  menuNum = 1; }											//|
			else Start.setFillColor(Color::White);																																//|
			if (IntRect(245, 260, 210, 20).contains(Mouse::getPosition(window))) { About.setFillColor(Color::Black);  menuNum = 2; }											//|
			else About.setFillColor(Color::White);																																//|
																																												//|
			if (IntRect(260, 290, 100, 20).contains(Mouse::getPosition(window))) { Exit.setFillColor(Color::Black); menuNum = 3; }												//|
			else Exit.setFillColor(Color::White);																																//|
																																												//|
																																												//|
			if (Mouse::isButtonPressed(Mouse::Left))																															//|
			{																																									//|
				if (menuNum == 1) isMenu = false;																																//|
				if (menuNum == 2) { window.draw(about); window.display(); while (!Keyboard::isKeyPressed(Keyboard::Escape)); }													//|
				if (menuNum == 3) { window.close(); isMenu = false; restart = false; isExit = true; }																			//|
																																												//|
			}																																									//|
																																												//|
			/*window.draw(menuBg);*/																																			//|
			window.draw(menu1);																																					//|
			window.draw(Start);																																					//|
			window.draw(About);																																					//|
			window.draw(Exit);																																					//|
			window.draw(Aut);																																					//|
			window.draw(Record);																																				//|
																																												//|
			/*window.draw(menu2);																																				//|
			window.draw(menu3);*/																																				//|
			window.display();																																					//|
		}																																										//|
		//------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
		file.close();
	}

	else {
		while (isMenu)																																							//|
		{																																										//|
																																												//|
			window.draw(wins);																																					//|
																																												//|
			/*window.draw(menu2);																																				//|
			window.draw(menu3);*/																																				//|
			window.display();																																					//|
		}
	}
}

