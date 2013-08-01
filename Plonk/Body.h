#pragma once
#include <SFML\System.hpp>
#include <vector>
#include "Shape.h"


class GameObject;
class World;

enum TBodyType{
	Dynamic,
	Static,
	Kinematic
};

class Body
{
public:
	Body(World* world);
	~Body(void);

	TBodyType Type;
	
	bool ignoreGravity;
	bool hasShape;

	std::vector<void (GameObject::*)(Body*)> collide;

	sf::Vector2f Position;
	sf::Vector2f Velocity;
	sf::Vector2f Acceleration;
	sf::Vector2f newPosition;
	
	sf::Vector2f LinearDamping;

	Shape* shape;

	GameObject* parent;

	void Update(float dTime);

	void SetShape(Shape* shape);
	void SetPosition(sf::Vector2f pos);

	void ResolveCollision(Body* other);
	void RectangleCollision(Body* other);

private:
	World* world;
};

