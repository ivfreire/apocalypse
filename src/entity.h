#pragma once

#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include "engine.h"

enum class EntityType { PLAYER, ZOMBIE, BULLET };

class Entity {
private:
	SDL_Rect rect;

public:
	std::string title;	
	SDL_Color color;

	Dynamics2 dynamics;
	Vector2 size;

	EntityType type;


	Entity(std::string title, Vector2 position, Vector2 size, EntityType type);

	void Update(float dtime);
	void Render(SDL_Renderer* rdr);

	~Entity();

};