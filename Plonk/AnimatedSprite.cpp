#include "AnimatedSprite.h"


AnimatedSprite::AnimatedSprite(sf::Vector2i tileSize, sf::Vector2i sheetSize) : SpriteSheet(tileSize, sheetSize)
{
}


void AnimatedSprite::AddAnimation(std::string name, std::vector<int> frames, float frameRate, bool loopAnimation){
	//TODO: Make sure the animation is valid etc
	animations[name] = new Animation(frames, frameRate, loopAnimation);
}

void AnimatedSprite::Start(std::string name){
	//TODO: Check that it exists first
	if(current != name){
		animations[name]->Start();
		current = name;
	}
}

void AnimatedSprite::Stop(){
	current = "";
}

void AnimatedSprite::Update(float dTime){
	if(current != ""){
		animations[current]->Update(dTime);
		Cell(animations[current]->GetCell());
	}
}
