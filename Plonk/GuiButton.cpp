#include "GuiButton.h"
#include "FontAsset.h"
#include "GuiState.h"
#include <iostream>


GuiButton::GuiButton(GuiState* state, sf::Vector2f btnPos, sf::Vector2f btnSize) : GuiElement(state)
{
	pos = btnPos;
	size = btnSize;
	
	text.setPosition(btnPos);
	text.setColor(sf::Color::Black);

	focus = false;
}


GuiButton::~GuiButton(void)
{
}


void GuiButton::Init(){

}

void GuiButton::LoadAssets(AssetManager* AssetManager){
	font = LoadFont("Lavoir");
	text.setFont(*font);
}

void GuiButton::Update(InputHandler* input){
	sf::Vector2f mousePos(input->getMousePos().x * State->Scale.x, input->getMousePos().y * State->Scale.y);


	if(ContainsPoint(mousePos)){
		text.setColor(sf::Color::Yellow);
		SendMessage("hover");

		if(input->isButtonPressed(sf::Mouse::Left)){
			text.setColor(sf::Color::Green);
			SendMessage("mouseDown");
		} else if(input->wasButtonReleased(sf::Mouse::Left)){
			SendMessage("mouseUp");
		} else {
			focus = true;
		}
	} else {
		text.setColor(sf::Color::Black);
		focus = false;
	}


}

void GuiButton::Draw(sf::RenderTarget* target, sf::RenderStates states){
	
	target->draw(text, states);
}

void GuiButton::setText(std::string newText){
	text.setString(newText);
	text.setCharacterSize(50);
}

bool GuiButton::ContainsPoint(sf::Vector2f point){
	if(point.x > pos.x + size.x ||
		point.x < pos.x ||
		point.y > pos.y + size.y ||
		point.y < pos.y){
			return false;
	} else {
		return true;
	}
}