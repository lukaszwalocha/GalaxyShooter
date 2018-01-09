#pragma once
#include<SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Asteroids.h"
class Player
{
private:
	sf::Texture playerTexture;
	sf::SoundBuffer buffer;
	sf::Sound deathSound;
public:
	sf::Sprite playerSprite;

	Player();
	~Player();
	void Player::playerMovement(sf::RenderWindow &, bool &);
	void asteroidCollision(Player &, std::vector<Asteroids> &, bool &, bool &, bool&, std::vector<Player> &, sf::Music &);
	void gameReset(bool &, bool &,bool &, unsigned int &,sf::RenderWindow &, sf::Text &, std::string &, Player &);
};