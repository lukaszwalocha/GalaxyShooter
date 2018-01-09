#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"
#include <time.h>
#include <iostream>
#include "Projectiles.h"
#include "Enemies.h"
#include "Asteroids.h"
#include "TextItems.h"
#include <Windows.h>


int main()
{
	//MAIN WINDOW
	sf::RenderWindow window(sf::VideoMode(1024, 768), "Galaxy Shooter by Tharnus, v.1.0", sf::Style::None);
	sf::Event event;
	window.setFramerateLimit(30);
	sf::Font ptsFont;
	ptsFont.loadFromFile("space.ttf");
	//POINTS DISPLAYING-START
	sf::Text ptsText("Points: ", ptsFont, 20);
	ptsText.setFont(ptsFont);
	ptsText.setFillColor(sf::Color::Green);
	ptsText.setPosition(window.getSize().x - window.getSize().x*0.99, 0);
	unsigned int pts = 0;
	std::string s;
	sf::Text ptsIncreasing;
	ptsIncreasing.setFont(ptsFont); 
	ptsIncreasing.setCharacterSize(20);
	ptsIncreasing.setString("0");
	ptsIncreasing.setFillColor(sf::Color::White);
	ptsIncreasing.setPosition(window.getSize().x - window.getSize().x*0.50, 0);
	//BOLLEANS TO MANAGE THE CODE
	bool playerAlive = true;
	bool menuActive = true;
	bool infoVisible = false;
	bool menuBack = false;


	//GAME BACKGROUND
	sf::Texture gameBackground;
	gameBackground.loadFromFile("tlo.png");
	sf::Sprite gbSprite;
	gbSprite.setTexture(gameBackground);
	//MENU BACKGROUND
	sf::Texture menuBackground;
	menuBackground.loadFromFile("tlo_menu.png");
	sf::Sprite spriteMenu;
	spriteMenu.setTexture(menuBackground);
	//MAIN MUSIC THEME
	sf::Music main_theme;
	main_theme.openFromFile("main_soundtrack.wav");
	//RANDOMIZING
	srand(time(NULL));
	//ANIMATION TIMER
	unsigned int animationCounter = 0;
	// OBJECTS
	Player player1;
	Projectiles projectile1;
	Enemies enemy1;
	Asteroids asteroid1;
	//MENU AND TEXT OBJECTS
	TextItems menuButtonStart(320, 200);
	TextItems menuButtonAbout(390, 300);
	TextItems menuButtonExit(410, 400);
	TextItems menuInfo(20, 200);
	TextItems menuButtonBack(430, 650);
	TextItems deathText(320, 300);
	TextItems scoreText(355, 400);
	TextItems escapeText(325, 500);
	TextItems ptsValueText(375, 400);
	//POINTERS TO OBJECTS

	Player *playerPtr = &player1;
	Projectiles *projectilePtr = &projectile1;
	Enemies *enemyPtr = &enemy1;
	Asteroids *asteroidPtr = &asteroid1;

	//POINTERS TO TEXT AND MENU OBJECTS

	TextItems *startPtr = &menuButtonStart;
	TextItems *aboutPtr = &menuButtonAbout;
	TextItems *exitPtr = &menuButtonExit;
	TextItems *infoPtr = &menuInfo;
	TextItems *backPtr = &menuButtonBack;
	TextItems *deathPtr = &deathText;
	TextItems *scorePtr = &scoreText;
	TextItems *escapePtr = &escapeText;
	TextItems *ptsPtr = &ptsValueText;

	//CONTAINERS--------------------------------------
	std::vector<Player> playerVector;
	std::vector<Projectiles> projectilesVector;
	std::vector<Enemies> enemiesVector;
	std::vector<Asteroids> asteroidsVector;
	asteroid1.addAsteroid(asteroidsVector, asteroid1);

	//ASTEROIDS POSITION-ORIGIN----------------------------------
	
	asteroid1.positionProtection(asteroidsVector, window);
	asteroid1.setAsteroidPosition(asteroidsVector, window);
	//GAME LOOP
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{

			switch (event.type)
			{
			case sf::Event::Closed:
			{
				window.close();
			}
			}
		}
		//SCREEN CLEARING
		window.clear();
		if (menuActive)
		{
			window.draw(spriteMenu);
		}
		else if (!menuActive)
		{
			
			window.draw(gbSprite);
		}
		if (!infoVisible&&menuActive)
		{
			//MENU BUTTONS
			startPtr->setTextString("Start Game", menuButtonStart);
			startPtr->setColor(menuButtonStart, 2);
			startPtr->setTextDesign(menuButtonStart, 4, 50, 3);
			startPtr->ButtonPressed(menuButtonStart, window, menuActive, infoVisible);
			startPtr->menuTextDisplay(window, menuActive);

			aboutPtr->setTextString("About", menuButtonAbout);
			aboutPtr->setColor(menuButtonAbout, 2);
			aboutPtr->setTextDesign(menuButtonAbout, 4, 50, 3);
			aboutPtr->ButtonPressed(menuButtonAbout, window, menuActive, infoVisible);
			aboutPtr->menuTextDisplay(window, menuActive);

			exitPtr->setTextString("Exit", menuButtonExit);
			exitPtr->setColor(menuButtonExit, 2);
			exitPtr->setTextDesign(menuButtonExit, 4, 50, 3);
			exitPtr->ButtonPressed(menuButtonExit, window, menuActive, infoVisible);
			exitPtr->menuTextDisplay(window, menuActive);
		}
		if (infoVisible)
		{//INFO DISPLAY
			infoPtr->setTextString("                                                       Hello Dear User!\n                                     I'm glad to greet you on board!\n                        Try to avoid asteroids and collect points\n                                    by destroying alien spaceships!\n                                                                   Beware!\n                    The asteroids are moving faster and faster!\n                                                  How to control the ship:\n                          A-move left, D-move right, Space bar-shot.\n                                             Good luck and have fun!", menuInfo);
			infoPtr->setColor(menuInfo, 2);
			infoPtr->setTextDesign(menuInfo, 1, 25, 1);
			infoPtr->textDisplay(window);

			backPtr->setTextString("Back", menuButtonBack);
			backPtr->setColor(menuButtonBack, 2);
			backPtr->setTextDesign(menuButtonBack, 4, 50, 3);
			backPtr->ButtonPressed(menuButtonBack, window, menuActive, infoVisible);
			backPtr->menuTextDisplay(window, menuActive);
		}
		
		//PLAYER INTERACTIONS
		if (playerAlive&&!menuActive)
		{
			playerPtr->playerMovement(window, playerAlive);
			playerPtr->asteroidCollision(player1, asteroidsVector, playerAlive, menuActive, menuBack, playerVector, main_theme);
			window.draw(ptsText);
			window.draw(ptsIncreasing);
		}
		//ASTEROIDS INTERACTIONS

		asteroidPtr->asteroidMovement(window,asteroidsVector, playerAlive, menuActive, menuBack);
		asteroidPtr->positionProtection(asteroidsVector, window);
		if (!menuActive)
		asteroidPtr->drawAsteroids(window, asteroidsVector);


		//ENEMIES INTERACTIONS

		enemyPtr->setEnemyPosition(window, enemy1, enemiesVector, playerAlive, animationCounter, menuActive);
		enemyPtr->enemyMovement(animationCounter);

		//PROJECTILES INTERACTIONS

		projectilePtr->shot(projectile1, player1, window, projectilesVector, playerAlive, asteroidsVector, pts, s, ptsIncreasing);
		projectilePtr->projectileCollision(projectilesVector, enemiesVector, pts, s, ptsIncreasing);

		//GAME RESET
		if (!playerAlive)
		{
			deathPtr->setTextString("GAME OVER!", deathText);
			deathPtr->setColor(deathText, 1);
			deathPtr->setTextDesign(deathText, 0, 60, 1);
			deathPtr->textDisplay(window);
			
			scorePtr->setTextString("Your Score:", scoreText);
			scorePtr->setColor(scoreText, 1);
			scorePtr->setTextDesign(scoreText, 0, 40, 0);
			scorePtr->textDisplay(window);

			escapePtr->setTextString("Press ESCAPE", escapeText);
			escapePtr->setColor(escapeText, 1);
			escapePtr->setTextDesign(escapeText, 0, 40, 1);
			escapePtr->textDisplay(window);

			
			ptsIncreasing.setPosition(500, 450);
			ptsIncreasing.setCharacterSize(40);
			ptsIncreasing.setFillColor(sf::Color::Green);
			window.draw(ptsIncreasing);


			playerPtr->gameReset(menuActive, playerAlive, menuBack, pts, window, ptsIncreasing, s, player1);
		}
		else if (playerAlive)
		{
			ptsIncreasing.setPosition(window.getSize().x - window.getSize().x*0.87, 0);
			ptsIncreasing.setFillColor(sf::Color::White);
			ptsIncreasing.setCharacterSize(20);
		}

		window.display();
	}

	return 0;
}


