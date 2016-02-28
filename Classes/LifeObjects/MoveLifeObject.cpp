#include "LifeObjects.h"

using namespace cocos2d;

void CLifeObject::Move(cocos2d::Vec2 shiftVector, float dt)
{
	direction = shiftVector;
	Vec2 resultVector = direction;

	resultVector *= velocity;
	resultVector *= dt;

	visual.Move(resultVector);
}

void CLifeObject::SetVelocity(float setVelocity)
{
	velocity = setVelocity;
}

float CLifeObject::GetVelocity() const
{
	return velocity;
}

void CLifeObject::SetPosition(Vec2 pos)
{
	visual.SetPosition(pos);
}

void CLifeObject::SetPosition(float x, float y)
{
	visual.SetPosition(x, y);
}

float CLifeObject::GetPositionX() const// TODo : collision
{
	return visual.GetPositionX();
}

float CLifeObject::GetPositionY() const// TODo : collision
{
	return visual.GetPositionY();
}

Vec2 CLifeObject::GetPosition() const
{
	return visual.GetPosition();// TODO : collision
}

void CLifeObject::GetCoordinateForView(GLView &view) const
{
	//view.setViewPortInPoints(visual.GetPosition(), view.getVisibleSize());
	//view.set
	assert(false);// TODO : not work
}