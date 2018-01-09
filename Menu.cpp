#include "Menu.h"
#include <iostream>
#include "Player.h"

Menu::Menu(bool &MenuAktywne, sf::RenderWindow &window, std::string text, float widthGiven, float heightGiven)
{
	this->text = text;
	this->height = heightGiven;
	this->width = widthGiven;

	button_text.setString(text);
	menuFont.loadFromFile("arial.ttf");
	button_text.setFont(menuFont);
	button_text.setFillColor(sf::Color::White);
	button_text.setPosition(widthGiven, heightGiven);
	button_text.setOutlineThickness(5);



}
Menu::Menu()
{

}

Menu::~Menu()
{
}

void gameReset(bool &menuActive, bool &playerAlive, bool &menuBack, unsigned int &ptsValue, sf::Text &tekst2, sf::Text &ptsAmount, std::string &s, Player &playerObject)
{

	menuBack = true;
	s = std::to_string(ptsValue);
	ptsAmount.setString(s);


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	{


		ptsValue = 0;
		s = std::to_string(ptsValue);
		tekst2.setString(s);

		menuActive = true;
		playerAlive = true;
		menuBack = false;




	}
	playerObject.playerSprite.setPosition(500, 600);


}


void Menu::drawButton(sf::RenderWindow &window, Menu &button1)
{


	window.draw(button1.button_text);



}


void Menu::isPressed(sf::RenderWindow &window, Menu &menuObject, bool &menuActive, bool &infoVisible)
{

	sf::Vector2f mousePosition(sf::Mouse::getPosition(window));




	if (menuObject.button_text.getGlobalBounds().contains(mousePosition) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		
		if (button_text.getString() == "About")
		{
			
			infoVisible = true;


		}
		else if (button_text.getString() == "Back")
		{
			infoVisible = false;
		}

		else if (button_text.getString() == "Exit")
		{
			
			window.close();
		}

		else
			menuActive = false;


	}
	else if (menuObject.button_text.getGlobalBounds().contains(mousePosition))
	{
		menuObject.button_text.setFillColor(sf::Color::Green);
	}
	else
	{
		menuObject.button_text.setFillColor(sf::Color::White);
		
	}

}

