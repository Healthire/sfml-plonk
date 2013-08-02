#include "Wall.h"
#include "Rectangle.h"


Wall::Wall(World* World, sf::Vector2f pos, sf::Vector2f size)
{
	this->size = size;
	this->pos = pos;
	isDrawable = true;
	isUpdatable = true;

	body = new Body(World, this);
	body->SetPosition(pos);
	Rectangle* shape = new Rectangle(size);
	body->SetShape(shape);
	body->Type = Static;
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

	sprite.setPosition(pos.x - size.x / 2, pos.y - size.y / 2);
	sprite.setScale(size);
	sprite.setColor(sf::Color::White);
	target->draw(sprite);
}

bool Wall::Collide(Collision coll){
	return 1;
}