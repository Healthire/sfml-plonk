#pragma once

#include "Game.h"
#include "StateManager.h"
#include "PlayState.h"

class Game1 : public Game
{
public:

	Game1();

	void Init();
	void LoadAssets(AssetManager* AssetManager);
	void Update(float dTime);
	void Draw(sf::RenderTarget* target);

	void Exit();

	StateManager* stateManager;
};

