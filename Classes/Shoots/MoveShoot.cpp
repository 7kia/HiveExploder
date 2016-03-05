#include "shoot.h"

using namespace cocos2d;

void CShoot::Move(cocos2d::Vec2 shiftVector, float dt)
{
	direction = shiftVector;
	Vec2 resultVector = direction;

	resultVector *= velocity;
	resultVector *= dt;

	CVisual::Move(resultVector);
}