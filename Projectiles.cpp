#include "Projectiles.h"
#include "Enemies.h"

Projectiles::Projectiles()
{
	projectileSprite.setPosition(playerSprite.getPosition().x, playerSprite.getPosition().y);
	projectileTexture.loadFromFile("beams.png");
	enemyDown.setBuffer(buffer2);
	buffer2.loadFromFile("smierc_przeciwnika.wav");
	sf::Texture *texturePtr = &projectileTexture;
	projectileSprite.setTexture(*texturePtr);
	projectileSprite.setTextureRect(sf::IntRect(30 * 0, 30 * 0, 30, 30));
	shotTimer = 0;
}


Projectiles::~Projectiles()
{
}
void Projectiles:: projectileCollision(std::vector<Projectiles> &projectilesVector, std::vector<Enemies> &enemiesVector, unsigned int &ptsValue, std::string &s, sf::Text &ptsText)
{

	for (int i = 0; i < enemiesVector.size(); i++)
	{
		for (int j = 0; j < projectilesVector.size(); j++)
		{
			if (enemiesVector[i].enemySprite.getGlobalBounds().intersects(projectilesVector[j].projectileSprite.getGlobalBounds()))
			{
				enemiesVector.erase(enemiesVector.begin() + i);
				projectilesVector.erase(projectilesVector.begin() + j);
				enemyDown.play();
				ptsValue++;
				
				s = std::to_string(ptsValue);
				ptsText.setString(s);
				break;
			}

		}

	}


}


void Projectiles::shot(Projectiles &projectile, Player &playerObject, sf::RenderWindow &window, std::vector<Projectiles> &projectilesVector, bool &playerAlive,
	std::vector<Asteroids> &asteroidsVector, unsigned int &pointsValue, std::string &s, sf::Text &pointsText)
{

	if (shotTimer < 15)
	{
		shotTimer++;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && shotTimer >= 15 && playerAlive)
	{

		projectile.projectileSprite.setPosition(playerObject.playerSprite.getPosition().x + 20, playerObject.playerSprite.getPosition().y - 7);
		projectilesVector.push_back(projectile);
		shotTimer = 0;


	}
	for (int i = 0; i < projectilesVector.size(); i++)
	{

		projectilesVector[i].projectileMovement();

		window.draw(projectilesVector[i].projectileSprite);

		if ((projectilesVector[i].projectileSprite.getPosition().y > 0) && (projectilesVector[i].projectileSprite.getGlobalBounds().intersects(asteroidsVector[0].asteroidSprite.getGlobalBounds()) ||
			projectilesVector[i].projectileSprite.getGlobalBounds().intersects(asteroidsVector[1].asteroidSprite.getGlobalBounds()) ||
			projectilesVector[i].projectileSprite.getGlobalBounds().intersects(asteroidsVector[2].asteroidSprite.getGlobalBounds()) ||
			projectilesVector[i].projectileSprite.getGlobalBounds().intersects(asteroidsVector[3].asteroidSprite.getGlobalBounds()) ||
			projectilesVector[i].projectileSprite.getGlobalBounds().intersects(asteroidsVector[4].asteroidSprite.getGlobalBounds())))
		{

			projectilesVector.erase(projectilesVector.begin() + i);
			if (pointsValue > 0)
			{
				pointsValue--;
				
				s = std::to_string(pointsValue);
				pointsText.setString(s);
			}

		}

		else if (projectilesVector[i].projectileSprite.getPosition().y < 0 || projectilesVector[i].projectileSprite.getGlobalBounds().intersects(asteroidsVector[0].asteroidSprite.getGlobalBounds())
			|| projectilesVector[i].projectileSprite.getGlobalBounds().intersects(asteroidsVector[1].asteroidSprite.getGlobalBounds())||
			projectilesVector[i].projectileSprite.getGlobalBounds().intersects(asteroidsVector[2].asteroidSprite.getGlobalBounds())||
			projectilesVector[i].projectileSprite.getGlobalBounds().intersects(asteroidsVector[3].asteroidSprite.getGlobalBounds())||
			projectilesVector[i].projectileSprite.getGlobalBounds().intersects(asteroidsVector[4].asteroidSprite.getGlobalBounds()))
		{

			projectilesVector.erase(projectilesVector.begin() + i);

		}

	}

}


void Projectiles::projectileMovement()
{

	projectileSprite.move(0, -10);



}