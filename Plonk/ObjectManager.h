#pragma once
#include <SFML\Graphics.hpp>
#include "GameObject.h"
#include "AssetManager.h"

class ObjectManager
{
public:
	ObjectManager(void);
	~ObjectManager(void);

	GameObject* getObject(int id);

	void LoadAssets(AssetManager* assetManager);
	void Update(float dTime);
	void Draw(sf::RenderTarget* target);

	float AddObject(TObjectType type, GameObject* object);
	void RemoveObject(int id);


private:
	int newID;
	std::vector<GameObject*> Objects;

	bool isLoaded;

	AssetManager* assetManager;

};

