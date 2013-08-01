#pragma once
#include <vector>
#include <SFML\Graphics.hpp>
#include "InputHandler.h"
#include "GuiElement.h"
#include "AssetManager.h"

class GuiMessage
{
public:
	GuiMessage(GuiElement* senderElement, std::string eventMessage){
		sender = senderElement;
		message = eventMessage;
	}

	GuiElement* GetSender(){ return sender; }
	std::string GetMessage(){ return message; }

private:
	GuiElement* sender;
	std::string message;
};

class GuiState
{
public:
	GuiState();

	sf::Vector2f Scale;

	void AddElement(GuiElement* newElement);
	void RemoveElement(int id);

	void LoadAssets(AssetManager* AssetManager);
	void Init();
	void Update(InputHandler* Input);
	void Draw(sf::RenderTarget* target, sf::RenderStates states = sf::RenderStates::Default);

	bool pollMessage();
	GuiMessage getMessage();
	void sendMessage(GuiElement* sender, std::string message);

	void setSize(sf::Vector2f newSize);
	void setViewport(sf::Vector2u viewportSize);


private:
	std::vector<GuiElement*> Elements;
	int newID;
	std::vector<GuiMessage> Messages;

	sf::View Camera;
	sf::Vector2u vpSize;
	sf::RenderStates renderStates;

};

