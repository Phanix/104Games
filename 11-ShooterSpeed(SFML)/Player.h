#pragma once
class Player {
public:
	
	sf::RectangleShape rect;
	
	float movementSpeed = 0.5;
	
	Player(float xPosition, float yPosition, sf::Texture &texture) {
		rect.setPosition(xPosition, yPosition);
		rect.setSize(sf::Vector2f(50, 50));
		rect.setTexture(&texture);
	}
	

	bool update() {
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) // Moving Down
		{
			
			return true;
			
		}
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) // Moving Left
		{
			rect.move(-movementSpeed, 0);
			
			
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) // Moving Right
		{
			rect.move(movementSpeed, 0);
			
			
		}
		return false;
		
		
	}

};