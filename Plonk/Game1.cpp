#include <iostream>
#include "Game1.h"
#include "MainMenu.h"

Game1::Game1(){
	Game::Game();


	
	frameRate = 2000;
	stateManager = new StateManager(&assetManager, this);
}

void Game1::Init(){
	//Set up window options before initiating Game
	SetWindowSize(sf::Vector2i(640, 480));

	Game::Init();

	Window->setVerticalSyncEnabled(true);
	Window->setFramerateLimit(60);

	stateManager->Init();

	PlayState* testState = new PlayState;
	//MainMenu* mainMenu = new MainMenu;
	stateManager->AddState(testState);

	
}

void Game1::LoadAssets(AssetManager* AssetManager){
	Game::LoadAssets(AssetManager);
}

void Game1::Update(float dTime){

	stateManager->Update(dTime);

	Game::Update(dTime);
}

void Game1::Draw(sf::RenderTarget* target){
	target->clear(sf::Color(0, 0, 0));

	stateManager->Draw(target);

	Window->display();
}

void Game1::Exit(){
	Window->close();
}
