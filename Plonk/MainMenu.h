#pragma once
#include "GameState.h"
#include "GuiState.h"


class MainMenu : public GameState
{
public:
	MainMenu();

	void Init();
	void LoadAssets(AssetManager* AssetManager);
	
	void Update(float dTime);
	void Draw(sf::RenderTarget* target);

	void HandleGuiMessage(GuiMessage message);

	void StartGame();

private:
	GuiState Gui;
	InputHandler* Input;
};

