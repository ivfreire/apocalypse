#include "bullet.h"

Bullet::Bullet(Vector2 position, Face facing, float speed, float mass) : Entity("Bullet", position, { 10.0f, 10.0f }, EntityType::BULLET) {
	this->speed = speed;
	this->mass = mass;
	this->facing = facing;

	this->color = { 0, 0, 255, 255 };

	this->SetLife(5.0f);

	this->SetVelocity();
}

Bullet::Bullet(Weapon* weapon) : Entity("Bullet", weapon->bulletSpawn, weapon->bulletSize, EntityType::BULLET) {
	this->facing = *weapon->facing;
	this->speed = weapon->bulletSpeed;

	this->color = { 0, 0, 255, 255 };

	this->SetLife(5.0f);

	this->SetVelocity();
}


// Sets the bullet velocity direction
void Bullet::SetVelocity() {
	if (this->facing == Face::NORTH) this->dynamics.velocity.set(Axis::VERTICAL,	-this->speed);
	if (this->facing == Face::WEST) this->dynamics.velocity.set(Axis::HORIZONTAL,	-this->speed);
	if (this->facing == Face::SOUTH) this->dynamics.velocity.set(Axis::VERTICAL,	 this->speed);
	if (this->facing == Face::EAST) this->dynamics.velocity.set(Axis::HORIZONTAL,	 this->speed);
}


Bullet::~Bullet() {

}