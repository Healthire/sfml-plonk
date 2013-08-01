#pragma once
#include "AssetManager.h"
#include "InputHandler.h"

class GuiState;

class GuiElement
{
public:
	GuiElement(GuiState* state);

	int getID();
	void setID(int id);

	virtual void Init() = 0;
	virtual void LoadAssets(AssetManager* AssetManager) = 0;
	virtual void Update(InputHandler* input) = 0;
	virtual void Draw(sf::RenderTarget* target, sf::RenderStates states = sf::RenderStates::Default) = 0;

	void setTag(std::string newTag);
	std::string getTag();

	void SendMessage(std::string msg);

protected:
	GuiState* State;
	int id;
	std::string tag;

};

