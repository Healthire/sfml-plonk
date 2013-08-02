#include "Collision.h"


Collision::Collision(Body* thisBody, Body* otherBody, sf::Vector2f normal)
{
	ThisBody = thisBody;
	OtherBody = otherBody;
	Normal = normal;
}


Collision::~Collision(void)
{
}
