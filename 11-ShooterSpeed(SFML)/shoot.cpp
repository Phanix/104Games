#include "shoot.h"

shoot::shoot()
{
}


shoot::shoot(sf::Texture &texture) {
	bullet.setTexture(&texture);
	bullet.setSize(sf::Vector2f(10, 10));
	
	
	
}

void shoot::update(float xPosition, float yPosition, int side)
{
	bullet.move(0, side);
	if (bullet.getPosition().y < 0)
		bullet.setPosition(xPosition, yPosition);
}
