#pragma once
#include "GameObject.h"
#include "Body.h"

class Ball : public GameObject
{
public:
	Ball(World* World, sf::Vector2f pos, sf::Vector2f size);
	~Ball(void);

	void Init();
	void LoadAssets(AssetManager* assetManager);

	void Update(float dTime);

	void Draw(sf::RenderTarget* target);

	bool Collide(Collision coll);

private:
	sf::Sprite ball;

	Body* body;

	sf::Vector2f pos;
	sf::Vector2f size;
	float rotation;

	float rotationDampeningFactor;
	float rotationTurnFactor;
	float speedTurnMaxvel;
	float minVelocity;
};

