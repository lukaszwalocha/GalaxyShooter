#include "Asteroids.h"


Asteroids::Asteroids()
{
	asteroidTexture.loadFromFile("asteroid1.png");
	sf::Texture *texturePtr = &asteroidTexture;
	asteroidSprite.setTexture(*texturePtr);
	asteroidSprite.setTextureRect(sf::IntRect(64 * 0, 64 * 0, 64, 64));
	velocity = 5;

}


Asteroids::~Asteroids()
{
}

void Asteroids::drawAsteroids(sf::RenderWindow &window, std::vector<Asteroids> &asteroidVect)
{
	for (int i = 0; i < asteroidVect.size(); i++)
	{
		window.draw(asteroidVect[i].asteroidSprite);
	}
}

void Asteroids::addAsteroid(std::vector<Asteroids> &asteroidsVect, Asteroids &asteroidObj)
{
	for (int i = 0; i < 5; i++) // SETTING ASTEROIDS AMOUNT AND PUSHING THEM INTO THE VECTOR
	{
		asteroidsVect.push_back(asteroidObj);
	}


}

void Asteroids::positionProtection(std::vector<Asteroids> &asteroidsVector, sf::RenderWindow &window)
{

	//ASTEROID 0
		if (asteroidsVector[0].asteroidSprite.getGlobalBounds().intersects(asteroidsVector[1].asteroidSprite.getGlobalBounds()))
		{
			asteroidsVector[0].asteroidSprite.setPosition(rand() % unsigned int(window.getSize().x - 0.95*window.getSize().x + 1), -(rand() % int(250) + 1));
		}
		else if (asteroidsVector[0].asteroidSprite.getGlobalBounds().intersects(asteroidsVector[2].asteroidSprite.getGlobalBounds()))
		{
			asteroidsVector[0].asteroidSprite.setPosition(rand() % unsigned int(window.getSize().x - 0.95*window.getSize().x + 1), -(rand() % int(250) + 1));
		}
		else if (asteroidsVector[0].asteroidSprite.getGlobalBounds().intersects(asteroidsVector[3].asteroidSprite.getGlobalBounds()))
		{
			asteroidsVector[0].asteroidSprite.setPosition(rand() % unsigned int(window.getSize().x - 0.95*window.getSize().x + 1), -(rand() % int(250) + 1));
		}
		else if (asteroidsVector[0].asteroidSprite.getGlobalBounds().intersects(asteroidsVector[4].asteroidSprite.getGlobalBounds()))
		{
			asteroidsVector[0].asteroidSprite.setPosition(rand() % unsigned int(window.getSize().x - 0.95*window.getSize().x + 1), -(rand() % int(250) + 1));
		}
		//ASTEROID 1
		if (asteroidsVector[1].asteroidSprite.getGlobalBounds().intersects(asteroidsVector[0].asteroidSprite.getGlobalBounds()))
		{
			asteroidsVector[1].asteroidSprite.setPosition(rand() % unsigned int(window.getSize().x - 0.95*window.getSize().x + 1), -(rand() % int(250) + 1));
		}
		else if (asteroidsVector[1].asteroidSprite.getGlobalBounds().intersects(asteroidsVector[2].asteroidSprite.getGlobalBounds()))
		{
			asteroidsVector[1].asteroidSprite.setPosition(rand() % unsigned int(window.getSize().x - 0.95*window.getSize().x + 1), -(rand() % int(250) + 1));
		}
		else if (asteroidsVector[1].asteroidSprite.getGlobalBounds().intersects(asteroidsVector[3].asteroidSprite.getGlobalBounds()))
		{
			asteroidsVector[1].asteroidSprite.setPosition(rand() % unsigned int(window.getSize().x - 0.95*window.getSize().x + 1), -(rand() % int(250) + 1));
		}
		else if (asteroidsVector[1].asteroidSprite.getGlobalBounds().intersects(asteroidsVector[4].asteroidSprite.getGlobalBounds()))
		{
			asteroidsVector[1].asteroidSprite.setPosition(rand() % unsigned int(window.getSize().x - 0.95*window.getSize().x + 1), -(rand() % int(250) + 1));
		}
		//ASTEROID 2
		if (asteroidsVector[2].asteroidSprite.getGlobalBounds().intersects(asteroidsVector[0].asteroidSprite.getGlobalBounds()))
		{
			asteroidsVector[2].asteroidSprite.setPosition(rand() % unsigned int(window.getSize().x - 0.95*window.getSize().x + 1), -(rand() % int(250) + 1));
		}
		else if (asteroidsVector[2].asteroidSprite.getGlobalBounds().intersects(asteroidsVector[1].asteroidSprite.getGlobalBounds()))
		{
			asteroidsVector[2].asteroidSprite.setPosition(rand() % unsigned int(window.getSize().x - 0.95*window.getSize().x + 1), -(rand() % int(250) + 1));
		}
		else if (asteroidsVector[2].asteroidSprite.getGlobalBounds().intersects(asteroidsVector[3].asteroidSprite.getGlobalBounds()))
		{
			asteroidsVector[2].asteroidSprite.setPosition(rand() % unsigned int(window.getSize().x - 0.95*window.getSize().x + 1), -(rand() % int(250) + 1));
		}
		else if (asteroidsVector[2].asteroidSprite.getGlobalBounds().intersects(asteroidsVector[4].asteroidSprite.getGlobalBounds()))
		{
			asteroidsVector[2].asteroidSprite.setPosition(rand() % unsigned int(window.getSize().x - 0.95*window.getSize().x + 1), -(rand() % int(250) + 1));
		}
		//ASTEROID 3
		if (asteroidsVector[3].asteroidSprite.getGlobalBounds().intersects(asteroidsVector[1].asteroidSprite.getGlobalBounds()))
		{
			asteroidsVector[3].asteroidSprite.setPosition(rand() % unsigned int(window.getSize().x - 0.95*window.getSize().x + 1), -(rand() % int(250) + 1));
		}
		 else if (asteroidsVector[3].asteroidSprite.getGlobalBounds().intersects(asteroidsVector[2].asteroidSprite.getGlobalBounds()))
		{
			asteroidsVector[3].asteroidSprite.setPosition(rand() % unsigned int(window.getSize().x - 0.95*window.getSize().x + 1), -(rand() % int(250) + 1));
		}
		else if (asteroidsVector[3].asteroidSprite.getGlobalBounds().intersects(asteroidsVector[4].asteroidSprite.getGlobalBounds()))
		{
			asteroidsVector[3].asteroidSprite.setPosition(rand() % unsigned int(window.getSize().x - 0.95*window.getSize().x + 1), -(rand() % int(250) + 1));
		}
		else if (asteroidsVector[3].asteroidSprite.getGlobalBounds().intersects(asteroidsVector[0].asteroidSprite.getGlobalBounds()))
		{
			asteroidsVector[4].asteroidSprite.setPosition(rand() % unsigned int(window.getSize().x - 0.95*window.getSize().x + 1), -(rand() % int(250) + 1));
		}
		//ASTEROID 4
		if (asteroidsVector[4].asteroidSprite.getGlobalBounds().intersects(asteroidsVector[0].asteroidSprite.getGlobalBounds()))
		{
			asteroidsVector[4].asteroidSprite.setPosition(rand() % unsigned int(window.getSize().x - 0.95*window.getSize().x + 1), -(rand() % int(250) + 1));
		}
		else if (asteroidsVector[4].asteroidSprite.getGlobalBounds().intersects(asteroidsVector[1].asteroidSprite.getGlobalBounds()))
		{
			asteroidsVector[4].asteroidSprite.setPosition(rand() % unsigned int(window.getSize().x - 0.95*window.getSize().x + 1), -(rand() % int(250) + 1));
		}
		else if (asteroidsVector[4].asteroidSprite.getGlobalBounds().intersects(asteroidsVector[2].asteroidSprite.getGlobalBounds()))
		{
			asteroidsVector[4].asteroidSprite.setPosition(rand() % unsigned int(window.getSize().x - 0.95*window.getSize().x + 1), -(rand() % int(250) + 1));
		}
		else if (asteroidsVector[4].asteroidSprite.getGlobalBounds().intersects(asteroidsVector[3].asteroidSprite.getGlobalBounds()))
		{
			asteroidsVector[4].asteroidSprite.setPosition(rand() % unsigned int(window.getSize().x - 0.95*window.getSize().x + 1), -(rand() % int(250) + 1));
		}



}
void Asteroids::asteroidMovement(sf::RenderWindow &window, std::vector<Asteroids> &asteroidVect, bool &playerAlive, bool &MenuAktywne, bool &menuBack)
{
	for (int i = 0; i < asteroidVect.size(); i++)
	{

		if (!MenuAktywne)
		{
			if (velocity < 30 && playerAlive)
			{
				velocity += 0.00025;
			}
			else
			{
				velocity = 5;
			}
			asteroidVect[i].asteroidSprite.move(0, velocity);

		}
		

		if (asteroidVect[i].asteroidSprite.getPosition().y > 800 && playerAlive)
		{
			asteroidVect[i].asteroidSprite.setPosition(rand() % int(window.getSize().x - 0.15*window.getSize().x) + 1, -(rand() % int(250) + 1));
		}
		else if (MenuAktywne)
			asteroidVect[i].asteroidSprite.setPosition(rand() % int(window.getSize().x - 0.15*window.getSize().x) + 1, -(rand() % int(250) + 1));


	}
}
void Asteroids::setAsteroidPosition(std::vector<Asteroids> &asteroidsVect, sf::RenderWindow &window)
{
	for (int i = 0; i < asteroidsVect.size(); i++){
		
		asteroidsVect[i].asteroidSprite.setPosition(rand() % int(800) + 1, -(rand() % int(250) + 1));
	}
	

}