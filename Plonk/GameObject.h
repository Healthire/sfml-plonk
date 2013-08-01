#pragma once
#include <SFML\Graphics.hpp>
#include "AssetManager.h"
#include "Body.h"

enum TObjectType{
	null,
	paddle,
	wall,
	ball
};

class GameObject
{
public:
	GameObject(void);

	int ID;
	TObjectType Type;

	bool isDrawable;
	bool isUpdatable;
	
	virtual void Init() = 0;
	virtual void LoadAssets(AssetManager* AssetManager) = 0;
	virtual void Update(float dTime) = 0;
	virtual void Draw(sf::RenderTarget* target) = 0;

	void Remove();

	bool isDying();

private:

	bool dying;

};

