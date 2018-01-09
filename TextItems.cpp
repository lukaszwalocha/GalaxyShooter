#include "TextItems.h"
#include <iostream>


TextItems::TextItems(float height, float width)

{
	this->text = text;
	this->windowHeight = height;
	this->windowWidth = width;
	textFont.loadFromFile("space.ttf");
	textObject.setFont(textFont);
	textObject.setCharacterSize(30);
	textObject.setPosition(height, width);
	textObject.setFillColor(sf::Color::Yellow);

	menuBuffer1.loadFromFile("menushooter.wav");
	menuSound1.setBuffer(menuBuffer1);
	timerm1 = 0;
	pulseTimerIncreasing = 0;
	pulseTimerDecreasing = 20;
	soundToBePlayed = true;
	textSize = 50;

}

TextItems::~TextItems()
{
}



void TextItems::setColor(TextItems &textObj, int colorNumber)
{

	switch (colorNumber)
	{
	case 0:textObj.textObject.setFillColor(sf::Color::Black); break;
	case 1:textObj.textObject.setFillColor(sf::Color::Red); break;
	case 2:textObj.textObject.setFillColor(sf::Color::White); break;
	case 3:textObj.textObject.setFillColor(sf::Color::Cyan); break;
	case 4:textObj.textObject.setFillColor(sf::Color::Blue); break;
	case 5:textObj.textObject.setFillColor(sf::Color::Magenta); break;
	}


}
void::TextItems::menuTextDisplay(sf::RenderWindow &window, bool &isMenuActive)
{
	if (isMenuActive)
		window.draw(textObject);


}

void::TextItems::textDisplay(sf::RenderWindow &window)
{

	window.draw(textObject);
}
void::TextItems::setTextString(std::string buttonString, TextItems &anyText)
{
	anyText.textObject.setString(buttonString);

}
void::TextItems::setPointsString(std::string &pointsAmountStr, TextItems &anyText)
{
	anyText.textObject.setString(pointsAmountStr);

}
void::TextItems::setTextDesign(TextItems &textObj, float textThickness, unsigned int charSize, unsigned int thicknessNumber)
{

	textObj.textObject.setOutlineThickness(textThickness);
	textObj.textObject.setCharacterSize(charSize);

	switch (thicknessNumber)
	{
	case 0:textObj.textObject.setOutlineColor(sf::Color::Green); break;
	case 1:textObj.textObject.setOutlineColor(sf::Color::Red); break;
	case 2:textObj.textObject.setOutlineColor(sf::Color::White); break;
	case 3:textObj.textObject.setOutlineColor(sf::Color::Black); break;
	case 4:textObj.textObject.setOutlineColor(sf::Color::Blue); break;
	case 5:textObj.textObject.setOutlineColor(sf::Color::Magenta); break;
	default:textObj.textObject.setOutlineColor(sf::Color::Transparent); break;
	}


}
void::TextItems::textPulsation(TextItems &text)
{


	if (pulseTimerDecreasing > 0 && pulseTimerIncreasing == 0)
	{
		pulseTimerDecreasing--;
		if (textSize>30)
			textSize--;

	}

	else if (pulseTimerDecreasing <= 0)
	{
		pulseTimerIncreasing++;
		if (textSize<50)
			textSize++;
		if (pulseTimerIncreasing >= 20)
		{
			pulseTimerIncreasing = 0;
			pulseTimerDecreasing = 20;
		}
	}

	text.textObject.setCharacterSize(textSize);


}

void::TextItems::ButtonPressed(TextItems &menuButtonObject, sf::RenderWindow &window, bool &menuAct, bool &infoVisible)
{
	sf::Vector2f mousePos(sf::Mouse::getPosition(window));

	if (timerm1 < 10 && soundToBePlayed == true)
	{

		timerm1++;
	}




	if (menuButtonObject.textObject.getGlobalBounds().contains(mousePos) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{

		if (menuButtonObject.textObject.getString() == "Start Game")
		{

			menuAct= false;
			

		}
		else if (menuButtonObject.textObject.getString() == "About")
		{
			infoVisible = true;

		}
		else if (menuButtonObject.textObject.getString() == "Back")
		{
			infoVisible = false;

		}

		else if (menuButtonObject.textObject.getString() == "Exit")
		{
			window.close();
		}
	


	}
	else if (menuButtonObject.textObject.getGlobalBounds().contains(mousePos) && (menuButtonObject.textObject.getString() == "Start Game" ||
		menuButtonObject.textObject.getString() == "About" || menuButtonObject.textObject.getString() == "Exit" || menuButtonObject.textObject.getString() == "Back" ))
	{
		menuButtonObject.textObject.setCharacterSize(60);
		menuButtonObject.textObject.setFillColor(sf::Color::Green);


		if (timerm1 >= 10 && soundToBePlayed == true&&menuAct)
		{

			menuSound1.play();
			soundToBePlayed = false;
			timerm1 = 0;
		}


	}

	else
	{
		menuButtonObject.textObject.setFillColor(sf::Color::White);
		soundToBePlayed = true;
	}

}
void setPointsToText(TextItems &textObj, unsigned int &ptsValue, std::string &s)
{
	
	textObj.textObject.setString(s);

}