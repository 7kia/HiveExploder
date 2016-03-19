#include "LifeObjects.h"

using namespace cocos2d;

void CLifeObject::Move(cocos2d::Vec2 shiftVector, float dt)
{
	m_direction = shiftVector;
	Vec2 resultVector = m_direction;

	resultVector *= m_velocity;
	resultVector *= dt;

	CVisual::Move(resultVector);
}

void CLifeObject::GetCoordinateForView(GLView &view) const
{
	assert(false);// TODO : not work
}