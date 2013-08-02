#include "PlayState.h"
#include "StateManager.h"
#include "Rectangle.h"
#include "Wall.h"
#include "Ball.h"


void PlayState::Init(){

	Input = new InputHandler(stateManager->game->Window);

	Camera.setSize(sf::Vector2f(640, 480));
	Camera.setCenter(sf::Vector2f(320, 240));
	
	ObjMgr.AddObject(wall, new Wall(&world, sf::Vector2f(320, 112.5), sf::Vector2f(640, 5)));
	ObjMgr.AddObject(wall, new Wall(&world, sf::Vector2f(320, 477.5), sf::Vector2f(640, 5)));
	ObjMgr.AddObject(wall, new Wall(&world, sf::Vector2f(2.5, 295), sf::Vector2f(5, 360)));
	ObjMgr.AddObject(wall, new Wall(&world, sf::Vector2f(637.5, 295), sf::Vector2f(5, 360)));
	ObjMgr.AddObject(ball, new Ball(&world, sf::Vector2f(20, 300), sf::Vector2f(20, 20)));

}

void PlayState::LoadAssets(AssetManager* AssetManager){
	ObjMgr.LoadAssets(AssetManager);
}

void PlayState::Update(float dTime){
	world.Update(dTime);
	ObjMgr.Update(dTime);
}

void PlayState::Draw(sf::RenderTarget* target){
	target->setView(Camera);
	ObjMgr.Draw(target);
}
