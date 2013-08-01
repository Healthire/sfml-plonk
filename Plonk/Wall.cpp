#include "Wall.h"


Wall::Wall(World* World, sf::Vector2f pos, sf::Vector2f size)
{
	this->size = size;
	this->pos = pos;

	isDrawable = true;
}


Wall::~Wall(void)
{
}

void Wall::Init(){
}

void Wall::LoadAssets(AssetManager* assetManager){
	sf::Texture* spriteTexture = static_cast<TextureAsset*>(assetManager->Load("pixel", Texture));
	sprite.setTexture(*spriteTexture);
}

void Wall::Update(float dTime){

	
}

void Wall::Draw(sf::RenderTarget* target){

	sprite.setPosition(pos);
	sprite.setScale(size);
	sprite.setColor(sf::Color::White);
	target->draw(sprite);
}