#pragma once
#include <SFML\System.hpp>

class Body;
class Rectangle;

enum TShapeType{
	Rect
};

class Shape
{
public:
	TShapeType Type;
	Body* body;

	virtual bool IntersectVisit(Shape* other) = 0;

	bool Intersect(Shape* shape);

	virtual bool Intersect(Rectangle* rect) = 0;

	virtual bool ContainsPoint(sf::Vector2f point) = 0;
};

