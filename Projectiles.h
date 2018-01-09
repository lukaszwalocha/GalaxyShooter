#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include"Player.h"
#include"Enemies.h"




class Projectiles:public Player
{
sf::Texture projectileTexture;
unsigned int shotTimer;
sf::SoundBuffer buffer2;
sf::Sound enemyDown;

public:
	Projectiles();
	~Projectiles();
	void projectileMovement();
	void shot(Projectiles &, Player &, sf::RenderWindow &, std::vector<Projectiles> &, bool &,std::vector<Asteroids> &, unsigned int &, std::string &, sf::Text &);
	void projectileCollision(std::vector<Projectiles> &, std::vector<Enemies> &, unsigned int &, std::string &, sf::Text &);

	sf::Sprite projectileSprite;
	

};

