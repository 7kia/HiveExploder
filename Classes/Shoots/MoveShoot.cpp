#include "shoot.h"

using namespace cocos2d;

void CShoot::Move(cocos2d::Vec2 shiftVector, float dt)
{
	direction = shiftVector;
	Vec2 resultVector = direction;

	resultVector *= velocity;
	resultVector *= dt;

	visual.Move(resultVector);
}

void CShoot::SetVelocity(float setVelocity)
{
	velocity = setVelocity;
}

float CShoot::GetVelocity() const
{
	return velocity;
}

void CShoot::SetPosition(Vec2 pos)
{
	visual.SetPosition(pos);
}

void CShoot::SetPosition(float x, float y)
{
	visual.SetPosition(x, y);
}

float CShoot::GetPositionX() const// TODo : collision
{
	return visual.GetPositionX();
}

float CShoot::GetPositionY() const// TODo : collision
{
	return visual.GetPositionY();
}

Vec2 CShoot::GetPosition() const
{
	return visual.GetPosition();// TODO : collision
}