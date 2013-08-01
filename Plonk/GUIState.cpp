#include "GUIState.h"

GuiState::GuiState(){
	newID = 0;

}

void GuiState::AddElement(GuiElement* element){
	element->setID(newID);
	newID++;
	Elements.push_back(element);
}

void GuiState::RemoveElement(int id){
	for(int i = 0; i < Elements.size(); i++){
		if(Elements[i]->getID() == id){
			Elements.erase(Elements.begin() + i);
		}
	}
}

void GuiState::Init(){
	//Set up camera to default
	setSize(sf::Vector2f(512, 288));
	Camera.setCenter(256, 144);

	//Set up renderstate
	renderStates.blendMode = sf::BlendNone;

	for(int i = 0; i < Elements.size(); i++){
		Elements[i]->Init();
	}
}

void GuiState::LoadAssets(AssetManager* AssetManager){
	for(int i = 0; i < Elements.size(); i++){
		Elements[i]->LoadAssets(AssetManager);
	}
}

void GuiState::Update(InputHandler* input){
	Messages.clear();

	for(int i = 0; i < Elements.size(); i++){
		Elements[i]->Update(input);
	}
}

void GuiState::Draw(sf::RenderTarget *target, sf::RenderStates states){
	target->setView(Camera);

	for(int i = 0; i < Elements.size(); i++){
		Elements[i]->Draw(target, states);
	}
}

bool GuiState::pollMessage(){
	if(Messages.size() > 0) return true;
	return false;
}

GuiMessage GuiState::getMessage(){
	GuiMessage returnMsg = Messages[0];
	Messages.erase(Messages.begin());
	return returnMsg;
}


void GuiState::sendMessage(GuiElement* sender, std::string message){
	Messages.push_back(GuiMessage(sender, message));
}

void GuiState::setSize(sf::Vector2f newSize){
	Camera.setSize(newSize);
	Scale.x = newSize.x / vpSize.x;
	Scale.y = newSize.y / vpSize.y;
	Camera.setCenter(newSize.x * 0.5, newSize.y * 0.5);
}

void GuiState::setViewport(sf::Vector2u viewportSize){
	vpSize = viewportSize;
	Scale.x = Camera.getSize().x / vpSize.x;
	Scale.y = Camera.getSize().y / vpSize.y;
}