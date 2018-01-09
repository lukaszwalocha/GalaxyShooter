#pragma once
#include<SFML/Graphics.hpp>
class Asteroids
{
private:
	sf::Texture asteroidTexture;
	float velocity;

public:
	sf::Sprite asteroidSprite;
	
	Asteroids();
	~Asteroids();
	void asteroidMovement(sf::RenderWindow &,std::vector<Asteroids> &, bool&, bool&, bool&);
	void setAsteroidPosition(std::vector<Asteroids> &, sf::RenderWindow &);
	void positionProtection(std::vector<Asteroids> &, sf::RenderWindow &);
	void addAsteroid(std::vector<Asteroids> &, Asteroids &);
	void drawAsteroids(sf::RenderWindow &, std::vector<Asteroids> &);
};

