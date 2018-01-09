#include "Enemies.h"


Enemies::Enemies()
{
	
	enemyTexture.loadFromFile("ufo.png");
	sf::Texture *texturePtr = &enemyTexture;
	enemySprite.setTexture(*texturePtr);
	enemySprite.setTextureRect(sf::IntRect(48 * 0, 42 * 0, 42, 48));
	
	
}


Enemies::~Enemies()
{
	

}
void Enemies::enemyMovement(unsigned int &animationCounter)
{

	enemySprite.move(0, 3);
	enemySprite.setTextureRect(sf::IntRect(48 * animationCounter, 42 * 0, 42, 48));


}
void Enemies::setEnemyPosition(sf::RenderWindow &window, Enemies &enemyObject, std::vector<Enemies> &enemiesVector, bool &playerAlive, unsigned int &animationCounter, bool&menuAct)
{
	animationCounter++;

	if (animationCounter == 7)
	{
		animationCounter = 0;
	}

	if (enemiesRespTimer < 5)
	{
		
		enemiesRespTimer++;
	}


	if (enemiesRespTimer >= 5 && enemiesVector.size() < 4 && playerAlive == true)
	{


		enemyObject.enemySprite.setPosition(rand() % int(window.getSize().x - 100) + 1, -50);


		
		enemiesVector.push_back(enemyObject);
		
		enemiesRespTimer = 0;
		
	}
	else if (menuAct)
		enemiesVector.clear();
	
	
	

	for (int i = 0; i < enemiesVector.size(); i++)
	{

		window.draw(enemiesVector[i].enemySprite);

		enemiesVector[i].enemyMovement(animationCounter);
		if (enemiesVector[i].enemySprite.getPosition().y > 770)
		{
			enemiesVector.erase(enemiesVector.begin() + i);

		}
		

	}
	

}