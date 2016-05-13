#include<SFML\Graphics.hpp>
#include<SFML\Audio.hpp>
#include<iostream>
#include<sstream>
#include<random>
#include "Player.h"
#include "shoot.h"
#include<Windows.h>
int main()
{
	srand(time(0));
	//variables
	const int width = 700;
	const int height = 600;
	int points = 0;
	float velEnemy = 0.2;
	//font
	sf::Font font;
	if (!font.loadFromFile("Data/avaria.ttf"))
		return 0;
	//sound
	sf::SoundBuffer exploImage;
	if (!exploImage.loadFromFile("Data/explosion.wav"))
		return 0;
	sf::Sound destroy;
	destroy.setBuffer(exploImage);
	//enemy image
	sf::Texture alienImage;
	if (!alienImage.loadFromFile("Data/alien.png"))
		return 0;
	//enemy dead
	sf::Texture alienDead;
	if (!alienDead.loadFromFile("Data/alienExplo.png"))
		return EXIT_FAILURE;
	//ship image
	sf::Texture texture;
	if (!texture.loadFromFile("Data/ship.png"))
		return EXIT_FAILURE;
	sf::RectangleShape alien;
	alien.setTexture(&alienImage);
	alien.setSize(sf::Vector2f(50, 50));
	alien.setPosition(150, 100);

	//bullet image
	sf::Texture bulletImage;
	if (!bulletImage.loadFromFile("Data/bullet.png"))
		return EXIT_FAILURE;
	
	//score
	sf::Text score;
	score.setFont(font);
	score.setPosition(10, height - 50);
	score.setString("Points : 0");
	//end score
	
	sf::RenderWindow window(sf::VideoMode(width, height), "X1");
	
	

	Player player1(width/2, height-50, texture);

	
	
	shoot shooter(bulletImage);
	shoot alienShoot(bulletImage);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event)) {
			srand(time(nullptr));
			if (event.type == sf::Event::Closed)
				window.close();
			

			if (event.key.code == sf::Keyboard::Escape)
				window.close();
		}
		
		//logic alien move
		if (alien.getPosition().x > width - 50) 
			velEnemy = -0.2;
		
		if (alien.getPosition().x < 50)
			velEnemy = 0.2;
		
		
		//end logic
		
		window.clear(sf::Color::Black);
		
		std::stringstream text;
		bool go = false;
		
		text << "Player : " << points;
		score.setString(text.str());
		window.draw(score);
		//logic for alien
		alien.setTexture(&alienImage);
		if (alien.getGlobalBounds().intersects(shooter.bullet.getGlobalBounds())) {
			
			alien.setPosition(1 + rand() % width, 100);
			points++;
			destroy.play();

			alien.setTexture(&alienDead);
			Sleep(20);
			
		}
		
		

		
		//set player limits
		if (player1.rect.getPosition().x < 0)
			player1.rect.setPosition(0, player1.rect.getPosition().y);
		if (player1.rect.getPosition().x > width - 50)
			player1.rect.setPosition(width - 50, player1.rect.getPosition().y);
		alien.move(velEnemy, 0);
		window.draw(alien);
		if (player1.update())
		{
			shooter.update(player1.rect.getPosition().x, player1.rect.getPosition().y, -3);
			window.draw(shooter.bullet);
			
		}
		
		window.draw(player1.rect);
		window.display();

	}
	return 0;

}


