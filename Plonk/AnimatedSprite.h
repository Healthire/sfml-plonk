#pragma once
#include "SpriteSheet.h"
#include "Animation.h"
#include <string>
#include <map>

class AnimatedSprite : public SpriteSheet
{
public:
	AnimatedSprite(sf::Vector2i tileSize, sf::Vector2i sheetSize);

	void AddAnimation(std::string name, std::vector<int> frames, float frameRate, bool loopAnimation);
	void Start(std::string name);
	void Stop();

	void Update(float dTime);
	

private:
	std::map<std::string, Animation*> animations;
	std::string current;
};

