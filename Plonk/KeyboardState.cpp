#include "KeyboardState.h"

void KeyboardState::GetState(){
	for(int i = 0; i < sf::Keyboard::KeyCount; i++){
		if(sf::Keyboard::isKeyPressed((sf::Keyboard::Key)i)){
			PressedKeys[i] = true;
		} else {
			PressedKeys[i] = false;
		}
	}
}