#include <SFML\Graphics.hpp>
#include "StateManager.h"
#include "GameState.h"

StateManager::StateManager(AssetManager* assetManager, Game* game){
	this->assetManager = assetManager;
	this->game = game;
}
StateManager::~StateManager(){

}

void StateManager::Init(){
}


void StateManager::Update(float dTime){
	for(int i = 0; i < states.size(); i++){
		states[i]->Update(dTime);
	}
}

void StateManager::Draw(sf::RenderTarget* target){
	for(int i = 0; i < states.size(); i++){
		states[i]->Draw(target);
	}
}

void StateManager::AddState(GameState* state){
	state->stateManager = this;
	state->Init();
	state->LoadAssets(assetManager);

	states.push_back(state);
}

void StateManager::RemoveState(GameState* state){
	for(int i = 0; i < states.size(); i++){
		if(states[i] == state) states.erase(states.begin() + i);
	}
}