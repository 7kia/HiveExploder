#include "LifeObjects.h"

using namespace cocos2d;

void CLifeObject::update(float dt)
{
	UpdatePosition(dt);
}


void CLifeObject::UpdatePosition(float dt)
{
	Vec2 resultVector = direction;

	resultVector *= velocity;
	resultVector *= dt;

	CVisual::Move(resultVector);
}
