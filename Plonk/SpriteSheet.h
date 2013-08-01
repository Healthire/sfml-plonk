#pragma once
#include <SFML/Graphics.hpp>

class SpriteSheet : public sf::Sprite
{
public:
	SpriteSheet(sf::Vector2i tileSize, sf::Vector2i sheetSize);
	~SpriteSheet(void);

	void Cell(int cellNum);

private:
	sf::Vector2i size;
	sf::Vector2i tile;
};

