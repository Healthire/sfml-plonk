#pragma once
#include <SFML\System.hpp>
#include "GameObject.h"
#include "AssetManager.h"
#include "TextureAsset.h"

class Wall : public GameObject
{
public:
	Wall(World* World, sf::Vector2f pos, sf::Vector2f size);
	~Wall(void);

	void Init();
	void LoadAssets(AssetManager* assetManager);

	void Update(float dTime);

	void Draw(sf::RenderTarget* target);

protected:
	Body* body;
	sf::Sprite sprite;

	sf::Vector2f size;
	sf::Vector2f pos;
};

