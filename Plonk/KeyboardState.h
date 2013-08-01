#pragma once
#include <SFML\Graphics.hpp>

class KeyboardState
{
public:
	bool PressedKeys[sf::Keyboard::KeyCount];

	void GetState();
};

