#pragma once
#include<SFML/Graphics.hpp>
class Enemies
{
private:
	sf::Texture enemyTexture;
	unsigned int enemiesRespTimer;

	
public:
	Enemies();
	~Enemies();
	void enemyMovement(unsigned int &);
	void setEnemyPosition(sf::RenderWindow &, Enemies &, std::vector<Enemies> &, bool &, unsigned int &, bool&);

	sf::Sprite enemySprite;



};

