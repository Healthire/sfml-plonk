#pragma once
#include <SFML\Graphics.hpp>
#include "AssetManager.h"

class StateManager;
class GameState
{
public:

	StateManager* stateManager;

	virtual void Init();
	virtual void LoadAssets(AssetManager* AssetManager);
	virtual void Update(float dTime);
	virtual void Draw(sf::RenderTarget* target);
	
};

