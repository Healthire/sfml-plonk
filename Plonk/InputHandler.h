#pragma once
#include <SFML\Graphics.hpp>
#include "KeyboardState.h"
#include "MouseState.h"

class InputHandler
{
public:
	InputHandler(sf::Window* window);

	sf::Mouse Mouse;
	sf::Keyboard Keyboard;

	void Update(sf::Vector2f scale = sf::Vector2f(1, 1), sf::Vector2f offset = sf::Vector2f(0, 0));

	bool isKeyPressed(sf::Keyboard::Key);

	bool wasKeyPressed(sf::Keyboard::Key key);
	bool wasKeyReleased(sf::Keyboard::Key key);

	bool isButtonPressed(sf::Mouse::Button button);

	bool wasButtonPressed(sf::Mouse::Button button);
	bool wasButtonReleased(sf::Mouse::Button button);

	bool wasMouseMoved();

	sf::Vector2i getMousePos();

private:
	KeyboardState LastKeyboardState;
	KeyboardState CurrentKeyboardState;

	MouseState LastMouseState;
	MouseState CurrentMouseState;

	sf::Window* gameWindow;
};

