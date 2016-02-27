#include "LifeObjects.h"

using namespace cocos2d;

LifeObject::LifeObject()
{
}

LifeObject::~LifeObject()
{
}

void LifeObject::SetType(TypeLifeObject & setType)
{
	type = &setType;
	visual.SetTexture(type->GetTexture());
	visual.SetTextureRect(type->GetRectangle());
}

void LifeObject::Move(float dt)
{
	Vec2 resultVector = velocity;
	resultVector.x *= dt;
	resultVector.y *= dt;

	visual.Move(resultVector);
}

void LifeObject::Move(cocos2d::Vec2 shiftVector)
{
	visual.Move(shiftVector);
}

void LifeObject::GetCoordinateForView(GLView &view) const
{
	//view.setViewPortInPoints(visual.GetPosition(), view.getVisibleSize());
	//view.set
	assert(false);// TODO : not work
}

void LifeObject::Update(float dt)
{
}

void LifeObject::SetVelocity(Vec2 setVelocity)
{
	velocity = setVelocity;
}

void LifeObject::SetVelocity(float vx , float vy)
{
	velocity.x = vx;
	velocity.y = vy;
}

Vec2 LifeObject::GetVelocity() const
{
	return velocity;
}


bool LifeObject::GetStateDeath() const
{
	return isDeath;
}

Direction LifeObject::GetDirectionLook() const
{
	return direction;
}

void LifeObject::SetDirectionLook(const Direction setDirection)
{
	direction = setDirection;
}

void LifeObject::SetPosition(Vec2 pos)
{
	visual.SetPosition(pos);
}

float LifeObject::GetPosition(CVisual::IDCoordinate id) const// TODo : collision
{
	switch (id) {
	case CVisual::IDCoordinate::X:
		return visual.GetPosition(CVisual::IDCoordinate::X);
	case CVisual::IDCoordinate::Y:
		return visual.GetPosition(CVisual::IDCoordinate::Y);
	default:
		break;
	}
}

Vec2 LifeObject::GetPosition() const
{
	return visual.GetPosition();// TODO : collision
}
