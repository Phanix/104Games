#include<SFML\Graphics.hpp>
#include<SFML\Audio.hpp>
#include<iostream>
#include<sstream>
#include<conio.h>


int main()
{
	
	//variables
	const int width = 700;
	const int height = 600;
	float vel[] = { 0.3f, 0.3f };
	float velPad[] = { 0.0f, 0.0f };
	float velPad2[] = { 0.0f, 0.0f };
	int pointsPC = 0;
	int pointsPlayer = 0;
	//font
	sf::Font font;
	if (!font.loadFromFile("Data/avaria.ttf"))
		return 0;
	//sound
	sf::SoundBuffer hit;
	if (!hit.loadFromFile("Data/hit.wav"))
		return 0;
	sf::Sound kickPad;
	kickPad.setBuffer(hit);
	//ball image
	sf::Texture ballImage;
	if (!ballImage.loadFromFile("Data/ball.png"))
		return 0;
	//pad image
	sf::Texture pad2Image;
	if (!pad2Image.loadFromFile("Data/pad2.png"))
		return 0;
	//draw pad 2
	sf::RectangleShape pad2;
	pad2.setTexture(&pad2Image);
	pad2.setSize(sf::Vector2f(30.0f, 150.0f));
	pad2.setPosition(width - 60, height / 2);
	//pad 1 image
	sf::Texture padImage;
	if (!padImage.loadFromFile("Data/pad.png"))
		return 0;
	//draw pad 1
	sf::RectangleShape pad1;
	pad1.setTexture(&padImage);
	pad1.setSize(sf::Vector2f(30.0f, 150.0f));
	pad1.setPosition(60, height / 2);
	//ball
	sf::RectangleShape ball;
	ball.setTexture(&ballImage);
	ball.setSize(sf::Vector2f(30, 30));
	ball.setPosition(150, 100);

	///score
	//score
	sf::Text score;
	score.setFont(font);
	score.setPosition(10, height - 50);
	score.setString("Points : 0 Level : 0 ");
	//end score
	
	sf::RenderWindow window(sf::VideoMode(width, height), "Pong");
	
	sf::CircleShape circle;
	circle.setRadius(20.0f);
	circle.setFillColor(sf::Color::Magenta);
	circle.setPosition(150, 20);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event)) {
			srand(time(nullptr));
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down)
				velPad[1] = 1;
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)
				velPad[1] = -1;
			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Down)
				velPad[1] = 0;
			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Up)
				velPad[1] = 0;
			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape)
			{
				window.clear();
				std::cout << "Entter a key to coninue";
				_getch();
			}


		}
		//move ball
		ball.move(vel[0], vel[1]);

		//move pad player
		pad1.move(velPad[0], velPad[1]);

		//Computer move
		pad2.move(velPad2[0], velPad2[1]);
		//ball logic
		if (ball.getPosition().y < 30)
			vel[1] = 0.3f;
		if (ball.getPosition().y >= height - 30)
		{
			vel[1] = -0.3f;
			
		}

		//teste AI computer
		if (pad2.getPosition().y < ball.getPosition().y && pad2.getPosition().y > 10)
			if ((1 + rand() % 100) % 2 == 0)
				velPad2[1] = 0.3f;
			else
				velPad2[1] = 0.010f;
		if (pad2.getPosition().y > ball.getPosition().y && pad2.getPosition().y < height - 150)
			if ((1 + rand() % 100) % 2 == 0)
				velPad2[1] = -0.3f;
			else
				velPad2[1] = -0.010f;
		if (pad2.getPosition().y < 10)
			if ((1 + rand() % 100) % 2== 0)
				velPad2[1] = 0.3f;
			else
				velPad2[1] = 0.010f;
		if (pad2.getPosition().y > height - 150)
			if((1 + rand() % 100) % 2== 0)
				velPad2[1] = -0.3f;
			else
				velPad2[1] = -0.010f;

		
		//end teste ai computer

		//logic computer hit ball
		if (pad2.getGlobalBounds().intersects(ball.getGlobalBounds())) {
			vel[0] = -0.3f;
			vel[1] = 0.3;
			kickPad.play();
		}
		//logic player hit ball
		if (pad1.getGlobalBounds().intersects(ball.getGlobalBounds())) {
			vel[0] = 0.3f;
			vel[1] = -0.3;
			kickPad.play();
		}

		//end logic player hit ball
		
		//logic player colision
		if (pad1.getPosition().y < 10)
			velPad[1] = 0;
		if (pad1.getPosition().y > height - 150)
			velPad[1] = 0;
		//end player colision 

		//chech who win
		if (ball.getPosition().x < 0) {
			ball.setPosition(width / 2, height / 2);
			vel[0] = 0.3;
			pointsPC++;
			pad2.setPosition(width - 60, height / 2);
		}
		if (ball.getPosition().x > width) {
			ball.setPosition(width / 2, height / 2);
			pointsPlayer++;
			vel[0] = -0.3;
			pad2.setPosition(width - 60, height / 2);
		}
		
		window.clear(sf::Color::Black);
		std::stringstream text;

		text << "Player : " << pointsPlayer << " PC : " << pointsPC;
		score.setString(text.str());
		window.draw(score);
		window.draw(pad2);
		window.draw(ball);
		window.draw(pad1);
		window.display();

	}
	return 0;

}


