#include "GuiElement.h"
#include "GuiState.h"

GuiElement::GuiElement(GuiState* state){
	state->AddElement(this);
	State = state;
}

int GuiElement::getID(){
	return id;
}

void GuiElement::setID(int newID){
	id = newID;
}

void GuiElement::setTag(std::string newTag){
	tag = newTag;
}

std::string GuiElement::getTag(){
	return tag;
}

void GuiElement::SendMessage(std::string msg){
	State->sendMessage(this, msg);
}