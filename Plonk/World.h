#pragma once
#include <vector>
#include "Body.h"


class World
{
public:
	World(void);
	~World(void);

	std::vector<Body*> Bodies;

	sf::Vector2f Gravity;

	void AddBody(Body* Body);

	void Update(float dTime);

	std::vector<Body*> TestPoint(sf::Vector2f point);

private:

	void checkCollisions();
	void resolveCollision(Body* body1, Body* body2);

};

