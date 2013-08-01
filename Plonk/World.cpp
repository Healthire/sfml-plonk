#include "World.h"
#include "Shape.h"
#include <iostream>


World::World(void)
{
	Gravity = sf::Vector2f(0, 0);

}


World::~World(void)
{
}

void World::AddBody(Body* Body){
	Bodies.push_back(Body);
}

void World::Update(float dTime){
	for(int i = 0; i < Bodies.size(); i++){
		//Apply gravity
		Bodies[i]->Update(dTime);
	}

	checkCollisions();
}

void World::checkCollisions(){
	for(int i = 0; i < Bodies.size(); i++){
		Body* body1 = Bodies[i];

		if(body1->hasShape){
			for(int j = i+1; j < Bodies.size(); j++){
				Body* body2 = Bodies[j];
				if(body2->hasShape){
					if(body1->shape->Intersect(body2->shape)){
						resolveCollision(body1, body2);
					}
				}
			}
		}
	}
}

void World::resolveCollision(Body* body1, Body* body2){
	body1->ResolveCollision(body2);
	body2->ResolveCollision(body1);
}

std::vector<Body*> World::TestPoint(sf::Vector2f point){
	
	std::vector<Body*> returnVector;

	for(int i = 0; i < Bodies.size(); i++){
		if(Bodies[i]->shape->ContainsPoint(point)) returnVector.push_back(Bodies[i]);
	}

	return returnVector;

}
