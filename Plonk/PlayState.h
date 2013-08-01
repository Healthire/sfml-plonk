#pragma once
#include "GameState.h"
#include "InputHandler.h"
#include "ObjectManager.h"
#include "World.h"
#include "Wall.h"


class PlayState : public GameState
{
public:
	void Init();
	void LoadAssets(AssetManager* AssetManager);
	
	void Update(float dTime);
	void Draw(sf::RenderTarget* target);

	ObjectManager ObjMgr;
	sf::View Camera;
private:
	InputHandler* Input;
	World world;
};

