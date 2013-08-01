#pragma once
#include <SFML\Graphics.hpp>
#include "AssetManager.h"

class Game
{
public:
	sf::RenderWindow* Window;
	sf::VideoMode videoMode;
	sf::ContextSettings Context;

	sf::Vector2i WindowSize;
	bool isFullscreen;
	float frameRate;
	AssetManager assetManager;


	Game(void);
	~Game(void);
	
	void Run();
	
	
	void SetWindowSize(sf::Vector2i newSize);
	void ToggleFullscreen();

	virtual void Exit();
	
	virtual void Init();
	virtual void LoadAssets(AssetManager* AssetManager);
	virtual void Update(float dTime);
	virtual void Draw(sf::RenderTarget* target);

private:
	sf::Clock Clock;


	float dTime;
	
	void setWindowSize(sf::Vector2i newSize);
	void GameLoop();
};

