#include "LifeObjects.h"

void LifeObject::Update(float dt)
{
	UpdatePosition(dt);
}

void LifeObject::UpdatePosition(float dt)
{
	visual.Move(velocity * dt);
}
