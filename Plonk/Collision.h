#pragma once
#include "Body.h"

class Collision
{
public:
	Collision(Body* thisBody, Body* otherBody, sf::Vector2f normal);
	~Collision(void);

	Body* ThisBody;
	Body* OtherBody;
	sf::Vector2f Normal;
};

