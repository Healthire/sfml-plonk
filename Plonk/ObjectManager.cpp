#include "ObjectManager.h"


ObjectManager::ObjectManager()
{
	isLoaded = false;
	newID = 0;
}


ObjectManager::~ObjectManager(void)
{
}

GameObject* ObjectManager::getObject(int id){
	for(int i = 0; i < Objects.size(); i++){
		if(Objects[i]->ID == id) return Objects[i];
	}
	return 0;
}

void ObjectManager::LoadAssets(AssetManager* assetManager){
	isLoaded = true;
	this->assetManager = assetManager;

	for(int i = 0; i < Objects.size(); i++){
		if(Objects[i]->isDrawable) Objects[i]->LoadAssets(assetManager);
	}
}

void ObjectManager::Update(float dTime){
	for(int i = 0; i < Objects.size(); i++){
		if(Objects[i]->isUpdatable) Objects[i]->Update(dTime);
		if(Objects[i]->isDying()) RemoveObject(i);
	}

}

void ObjectManager::Draw(sf::RenderTarget* target){
	for(int i = 0; i < Objects.size(); i++){
		if(Objects[i]->isDrawable) Objects[i]->Draw(target);
	}
}

float ObjectManager::AddObject(TObjectType type, GameObject* object){
	object->Type = type;
	object->ID = newID;

	object->Init();
	if(object->isDrawable && isLoaded) static_cast<GameObject*>(object)->LoadAssets(assetManager);

	Objects.push_back(object);

	newID++;

	return object->ID;
}

void ObjectManager::RemoveObject(int id){
	for(int i = 0; i < Objects.size(); i++){
		if(Objects[i]->ID == id){
			GameObject* delObject = Objects[i];
			Objects.erase(Objects.begin() + i);
			delete delObject;
		}
	}
}
