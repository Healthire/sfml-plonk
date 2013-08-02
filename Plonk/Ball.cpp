#include "Ball.h"
#include "TextureAsset.h"
#include "Rectangle.h"
#include <iostream>


Ball::Ball(World* World, sf::Vector2f pos, sf::Vector2f size)
{
	isDrawable = true;
	isUpdatable = true;

	this->pos = pos;
	this->size = size;

	body = new Body(World, this);
	body->SetPosition(pos);
	
	Rectangle* shape = new Rectangle(size);
	body->SetShape(shape);
	body->Type = Dynamic;
	body->Restitution = 1;

	ball.setOrigin(0.5, 0.5);

	rotationDampeningFactor = 0.5;

	minVelocity = 200;
	rotationTurnFactor = 5;
	speedTurnMaxvel = 800;
}


Ball::~Ball(void)
{
}

void Ball::Init(){
	body->Velocity = sf::Vector2f(500, 0);
	body->AngularVelocity = 2000;
	body->maxAngularVelocity = 2000;
}

void Ball::LoadAssets(AssetManager* assetManager){
	ball.setTexture(*static_cast<TextureAsset*>(assetManager->Load("pixel", Texture)));
}

void Ball::Update(float dTime){
	pos = body->Position;
	rotation = body->Rotation;

	//Ball slows down when it has rotation
	body->LinearDamping = sf::Vector2f(1, 1) * rotationDampeningFactor * abs(body->AngularVelocity) / body->maxAngularVelocity;

	float totalVel = sqrt((body->Velocity.x * body->Velocity.x) + (body->Velocity.y * body->Velocity.y));
	sf::Vector2f normalVelocity = sf::Vector2f(body->Velocity.x / totalVel, body->Velocity.y / totalVel);
	if(totalVel < minVelocity){
		body->Velocity = normalVelocity * minVelocity;
		totalVel = minVelocity;
	}

	//Ball turns in air when it has rotation
	float velAngle = atan2(normalVelocity.y, normalVelocity.x);
	velAngle += rotationTurnFactor * (body->AngularVelocity / body->maxAngularVelocity) * ((totalVel - minVelocity) / speedTurnMaxvel) * dTime;
	sf::Vector2f newNormalVelocity = sf::Vector2f(cos(velAngle), sin(velAngle));
	float lnNewNormalVelocity = sqrt((newNormalVelocity.x * newNormalVelocity.x) + (newNormalVelocity.y * newNormalVelocity.y));
	body->Velocity = newNormalVelocity / lnNewNormalVelocity * totalVel;
}

void Ball::Draw(sf::RenderTarget* target){
	
	ball.setRotation(rotation);
	ball.setPosition(pos);
	ball.setScale(size);
	target->draw(ball);
}

bool Ball::Collide(Collision coll){
	
	float totalVel = sqrt((body->Velocity.x * body->Velocity.x) + (body->Velocity.y * body->Velocity.y));
	sf::Vector2f normalVel = sf::Vector2f(body->Velocity.x / totalVel, body->Velocity.y / totalVel);
	float moveAngle = atan2(normalVel.y, normalVel.x);
	float spinAngle = moveAngle + (body->AngularVelocity / body->maxAngularVelocity) * 0.5;
	

	float normalAngle = atan2(coll.Normal.y, coll.Normal.x);

	float angleDiff = normalAngle - spinAngle;

	if(angleDiff < -1.5) spinAngle = normalAngle - 1.5;
	if(angleDiff > 1.5) spinAngle = normalAngle + 1.5;

	sf::Vector2f spinVector = sf::Vector2f(cos(spinAngle), sin(spinAngle));

	totalVel +=  (200 * abs(body->AngularVelocity / body->maxAngularVelocity));
	body->Velocity = sf::Vector2f(spinVector.x * totalVel, spinVector.y * totalVel);
	//body->AngularVelocity *= 0.25;
	
	return 1;
}
