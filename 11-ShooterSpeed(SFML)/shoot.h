#pragma once
#include<SFML\Graphics.hpp>


class shoot
{
public:
	int vel = 0;
	
	sf::RectangleShape bullet;
	
	
	shoot();
	shoot(sf::Texture &texture);
	void update(float xPosition, float yPosition,int side);
	
};

