#include "LifeObjects.h"

using namespace cocos2d;

void CLifeObject::Move(cocos2d::Vec2 shiftVector, float dt)
{
	direction = shiftVector;
	Vec2 resultVector = direction;

	resultVector *= velocity;
	resultVector *= dt;

	setPosition(getPosition() + resultVector);

	direction = Vec2::ZERO;
}

void CLifeObject::GetCoordinateForView(GLView &view) const
{
	//view.setViewPortInPoints(visual.GetPosition(), view.getVisibleSize());
	//view.set
	assert(false);// TODO : not work
}