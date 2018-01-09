#include "Player.h"
#include "Asteroids.h"

Player::Player()
{
	playerTexture.loadFromFile("statek.png");
	sf::Texture *texturePtr = &playerTexture;
	playerSprite.setTexture(*texturePtr);
	playerSprite.setTextureRect(sf::IntRect(48 * 0, 50 * 0, 51, 52));
	playerSprite.setPosition(sf::Vector2f(500, 600));
	buffer.loadFromFile("smierc_gracza.wav");
	deathSound.setBuffer(buffer);
}


Player::~Player()
{
}

void Player::playerMovement(sf::RenderWindow &window, bool &playerAlive)
{
	


	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)||sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) && playerSprite.getPosition().x>5)
	{
		playerSprite.move(-16, 0);


	}


	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) ||sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) && playerSprite.getPosition().x<955)
	{
		playerSprite.move(16, 0);

	}
	if (playerAlive)
	window.draw(playerSprite);

}

void Player::gameReset(bool &menuAct, bool &playerAlive,bool &menuBack,  unsigned int &pts, sf::RenderWindow &window, sf::Text &ptsAmount, std::string &s, Player &player)
{

	/*if (!playerAlive&& !menuBack)
	{
		s = std::to_string(pts);
		
		sf::Text ptsAfterGame;
		ptsAfterGame.setPosition(100, 100);
		ptsAfterGame.setString(s);
		window.draw(ptsAfterGame);
	
	}*/

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	{


		pts = 0;
		s = std::to_string(pts);
		ptsAmount.setString(s);

		menuAct = true;
		playerAlive = true;
		menuBack = false;
		

		player.playerSprite.setPosition(500, 600);

	}
	


}



void Player::asteroidCollision(Player &playerObject, std::vector<Asteroids> &asteroidVect, bool &playerAlive, bool &menuActive, bool& menuBack, std::vector<Player> &playerVector, sf::Music &mainSoundtrack)
{

	if (playerVector.empty() && !menuBack)
	{

		playerVector.push_back(playerObject);
		if (!menuActive)
		{
			mainSoundtrack.play();
			mainSoundtrack.setLoop(true);
			menuBack = true;

		}
	}

	for (int i = 0; i < asteroidVect.size(); i++)
	{
		if (playerObject.playerSprite.getGlobalBounds().intersects(asteroidVect[i].asteroidSprite.getGlobalBounds()))
		{
			playerAlive = false;
			for (int j = 0; j < playerVector.size(); j++)
			{

				playerVector.clear();
				mainSoundtrack.setLoop(false);
				mainSoundtrack.stop();
				deathSound.play();
				//fail.play();
			}
		}
	}

}