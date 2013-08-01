#pragma once
#include <SFML\Graphics.hpp>
#include "GameState.h"
#include "Game.h"


class StateManager
{
public:
	StateManager(AssetManager* assetManager, Game* game);
	~StateManager();

	Game* game;
	AssetManager* assetManager;

	void Init();
	void Update(float dTime);
	void Draw(sf::RenderTarget* target);

	void AddState(GameState* state);
	void RemoveState(GameState* state);

private:
	std::vector <GameState*> states;

};

