#pragma once
#include <SFML\System.hpp>
#include "Shape.h"

class Rectangle : public Shape
{
public:
	Rectangle(sf::Vector2f size);
	~Rectangle(void);
	
	sf::Vector2f Size;

	bool IntersectVisit(Shape* other);
	bool Intersect(Rectangle* rect);


	bool ContainsPoint(sf::Vector2f point);
};

