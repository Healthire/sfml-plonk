#include "Game.h"
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>

#include "AssetManager.h"

Game::Game(void)
{
	Clock = sf::Clock();
	Context = sf::ContextSettings(0, 0, 0, 2, 0);
	videoMode = sf::VideoMode::getFullscreenModes()[3];

	assetManager = AssetManager();

	frameRate = 60;
}


Game::~Game(void)
{
}
void Game::Run(){
	Init();
	LoadAssets(&assetManager);

	GameLoop();
}

void Game::SetWindowSize(sf::Vector2i newSize){
	setWindowSize(newSize);
}

void Game::setWindowSize(sf::Vector2i newSize){
	videoMode.height = newSize.y;
	videoMode.width = newSize.x;
}

void Game::ToggleFullscreen(){
	if(isFullscreen){
		videoMode = videoMode.getDesktopMode();
		Window->close();
		Window = new sf::RenderWindow(videoMode, "Game title", sf::Style::Default, Context);
		isFullscreen = false;
	} else {
		videoMode = sf::VideoMode::getFullscreenModes()[0];
		Window->close();
		Window = new sf::RenderWindow(videoMode, "Game title", sf::Style::Fullscreen, Context);
		isFullscreen = true;
	}
}

void Game::Init(){
	Window = new sf::RenderWindow(videoMode, "Game title", sf::Style::Close, Context);
}

void Game::LoadAssets(AssetManager* AssetManager){

}

void Game::Update(float dTime){

}

void Game::Draw(sf::RenderTarget* target){

}

void Game::GameLoop(){

	dTime = 0;

	while(Window->isOpen()){
		
		sf::Time newTime = Clock.getElapsedTime();
		dTime = newTime.asSeconds();
		Clock.restart();

		sf::Event closeEvent;
		while (Window->pollEvent(closeEvent))
		{
			if (closeEvent.type == sf::Event::Closed)
				Window->close();
		}

		Update(dTime);
		Draw(Window);

		
		sf::Time executeTime = Clock.getElapsedTime();
		sf::Time sleepTime = sf::microseconds(1000000 / frameRate - executeTime.asMicroseconds());
		sf::sleep(sleepTime);
		
		


	}
}

void Game::Exit(){
	Window->close();
}