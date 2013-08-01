#include "Rectangle.h"
#include "body.h"


Rectangle::Rectangle(sf::Vector2f size)
{
	Type = Rect;
	Size = size;
}

Rectangle::~Rectangle(void)
{
}

bool Rectangle::IntersectVisit(Shape* other){
	return other->Intersect(this);
}

bool Rectangle::Intersect(Rectangle* rect){
	if(body->newPosition.x - Size.x/2 > rect->body->newPosition.x + rect->Size.x/2 ||
		body->newPosition.x + Size.x/2 < rect->body->newPosition.x - rect->Size.x/2 ||
		body->newPosition.y - Size.y/2 > rect->body->newPosition.y + rect->Size.y/2 ||
		body->newPosition.y + Size.y/2 < rect->body->newPosition.y - rect->Size.y/2)
			return false;
	else 
		return true;
}

bool Rectangle::ContainsPoint(sf::Vector2f point){
	if(point.x < body->newPosition.x - Size.x/2 ||
		point.x > body->newPosition.x + Size.x/2 ||
		point.y < body->newPosition.y - Size.y/2 ||
		point.y > body->newPosition.y + Size.y/2)
			return false;
	else
		return true;
}
