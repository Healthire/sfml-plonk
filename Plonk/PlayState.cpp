#include "PlayState.h"
#include "StateManager.h"
#include "Rectangle.h"
#include "Wall.h"


void PlayState::Init(){

	Input = new InputHandler(stateManager->game->Window);

	Camera.setSize(sf::Vector2f(640, 480));
	Camera.setCenter(sf::Vector2f(320, 240));
	
	ObjMgr.AddObject(wall, new Wall(&world, sf::Vector2f(0, 110), sf::Vector2f(640, 5)));
	ObjMgr.AddObject(wall, new Wall(&world, sf::Vector2f(0, 475), sf::Vector2f(640, 5)));
}

void PlayState::LoadAssets(AssetManager* AssetManager){
	ObjMgr.LoadAssets(AssetManager);
}

void PlayState::Update(float dTime){
	ObjMgr.Update(dTime);
}

void PlayState::Draw(sf::RenderTarget* target){
	target->setView(Camera);
	ObjMgr.Draw(target);
}
