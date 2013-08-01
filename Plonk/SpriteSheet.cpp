#include "SpriteSheet.h"


SpriteSheet::SpriteSheet(sf::Vector2i tileSize, sf::Vector2i sheetSize)
{
	tile = tileSize;
	size = sheetSize;
}


SpriteSheet::~SpriteSheet(void)
{
}

void SpriteSheet::Cell(int cellNum){
	int xCell = cellNum % size.x;
	int yCell = floor(static_cast<float>(cellNum / size.x));
	
	int xPos = xCell * tile.x;
	int yPos = yCell * tile.y;

	sf::Sprite::setTextureRect(sf::IntRect(xPos, yPos, tile.x, tile.y));
}
