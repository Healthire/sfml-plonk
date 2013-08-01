#pragma once
#include <SFML\Graphics.hpp>

class MouseState
{
public:

	bool PressedButtons[sf::Mouse::ButtonCount];

	sf::Vector2i Pos;
	
	void GetState(sf::Window* window, sf::Vector2f scale = sf::Vector2f(1, 1), sf::Vector2f offset = sf::Vector2f(0, 0));

};

