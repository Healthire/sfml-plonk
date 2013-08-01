#include "InputHandler.h"


InputHandler::InputHandler(sf::Window* window)
{
	gameWindow = window;

	CurrentKeyboardState.GetState();
	LastKeyboardState = CurrentKeyboardState;

	CurrentMouseState.GetState(gameWindow);
	LastMouseState = CurrentMouseState;
}


void InputHandler::Update(sf::Vector2f scale, sf::Vector2f offset){
	LastKeyboardState = CurrentKeyboardState;
	CurrentKeyboardState.GetState();

	LastMouseState = CurrentMouseState;
	CurrentMouseState.GetState(gameWindow, scale, offset);
}

bool InputHandler::isKeyPressed(sf::Keyboard::Key key){
	if(CurrentKeyboardState.PressedKeys[key]){
		return true;
	} else {
		return false;
	}
}

bool InputHandler::wasKeyPressed(sf::Keyboard::Key key){
	if(!LastKeyboardState.PressedKeys[key] && CurrentKeyboardState.PressedKeys[key]){
		return true;
	} else {
		return false;
	}
}

bool InputHandler::wasKeyReleased(sf::Keyboard::Key key){
	if(LastKeyboardState.PressedKeys[key] && !CurrentKeyboardState.PressedKeys[key]){
		return true;
	} else {
		return false;
	}
}

bool InputHandler::isButtonPressed(sf::Mouse::Button button){
	if(CurrentMouseState.PressedButtons[button]){
		return true;
	} else {
		return false;
	}
}

bool InputHandler::wasButtonPressed(sf::Mouse::Button button){
	if(!LastMouseState.PressedButtons[button] && CurrentMouseState.PressedButtons[button]){
		return true;
	} else {
		return false;
	}
}

bool InputHandler::wasButtonReleased(sf::Mouse::Button button){
	if(LastMouseState.PressedButtons[button] && !CurrentMouseState.PressedButtons[button]){
		return true;
	} else {
		return false;
	}
}

bool InputHandler::wasMouseMoved(){
	if(LastMouseState.Pos != CurrentMouseState.Pos){
		return true;
	} else {
		return false;
	}
}

sf::Vector2i InputHandler::getMousePos(){
	return CurrentMouseState.Pos;
}