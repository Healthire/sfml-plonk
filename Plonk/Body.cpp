#include "Body.h"
#include "Rectangle.h"
#include "World.h"


Body::Body(World* world)
{
	world->AddBody(this);
	this->world = world;
	Type = Dynamic;
	ignoreGravity = false;
	hasShape = false;
}


Body::~Body(void)
{
}

void Body::SetShape(Shape* shape){
	this->shape = shape;
	shape->body = this;

	hasShape = true;
}

void Body::Update(float dTime){
	Position = newPosition;

	if(Type == Dynamic){
		Velocity.x += world->Gravity.x * dTime;
		Velocity.y += world->Gravity.y * dTime;
	}

	Velocity.x += Acceleration.x * dTime;
	Velocity.y += Acceleration.y * dTime;

	Velocity.x -= Velocity.x * LinearDamping.x * dTime;
	Velocity.y -= Velocity.y * LinearDamping.y * dTime;

	newPosition.x += Velocity.x * dTime;
	newPosition.y += Velocity.y * dTime;
}

void Body::SetPosition(sf::Vector2f pos){
	Position = pos;
	newPosition = Position;
}

void Body::ResolveCollision(Body* other){
	if(Type == Kinematic || Type == Static) return;
	if(other->Type == Kinematic) return;

	//Check this body's shape type and the other body's shape type and use the corresponding resolve method
	switch(shape->Type){
	case Rect:

		switch(other->shape->Type){
		case Rect:
			RectangleCollision(other);
			break;
		default:
			break;
		}

		break;
	default:
		break;
	}
}

void Body::RectangleCollision(Body* other){
	Rectangle* rect = static_cast<Rectangle*>(shape);
	Rectangle* otherRect = static_cast<Rectangle*>(other->shape);

	//Move half the collided length (other body will do the same) unless other body is static
	float moveFactor = 0.5;
	if(other->Type = Static) moveFactor = 1;

	//If the other body contains an entire edge, move the body so the edges just meet
	sf::Vector2f deltaPos;

	//If no full edge is contained, do a rough movement in the general direction of the collision
	float deltaY = (rect->Size.y/2 + otherRect->Size.y/2) - abs(newPosition.y - other->newPosition.y);
	float deltaX = (rect->Size.x/2 + otherRect->Size.x/2) - abs(newPosition.x - other->newPosition.x);

	if(deltaY < deltaX){
		if(newPosition.y - other->newPosition.y > 0){
			deltaPos.y -= deltaY;
		} else {
			deltaPos.y += deltaY;
		}
		Velocity.y = 0;
	} else {
		if(newPosition.x - other->newPosition.x > 0){
			deltaPos.x -= deltaX;
		} else {
			deltaPos.x += deltaX;
		}
		Velocity.x = 0;
	}

	deltaPos.x *= moveFactor;
	deltaPos.y *= moveFactor;

	newPosition.x -= deltaPos.x;
	newPosition.y -= deltaPos.y;
}