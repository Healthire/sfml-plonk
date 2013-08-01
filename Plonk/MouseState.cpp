#include "MouseState.h"

void MouseState::GetState(sf::Window* window, sf::Vector2f scale, sf::Vector2f offset){
	Pos = sf::Mouse::getPosition(*window);

	//Scale mouse position
	Pos.x *= scale.x;
	Pos.y *= scale.y;

	//Add offset to mouse position
	Pos.x += offset.x;
	Pos.y += offset.y;

	for(int i = 0; i < sf::Mouse::ButtonCount; i++){
		if(sf::Mouse::isButtonPressed((sf::Mouse::Button)i)){
			PressedButtons[i] = true;
		} else {
			PressedButtons[i] = false;
		}
	}
}
