#include "TypeShoots.h"

using namespace cocos2d;

void TypeShoot::SetTexture(Texture2D* setTexture)
{
	texture = setTexture;
}

cocos2d::Texture2D * TypeShoot::GetTexture() const
{
	return texture;
}

void TypeShoot::SetRect(cocos2d::Rect setRectangle)
{
	rectangle = setRectangle;
}

cocos2d::Rect TypeShoot::GetRectangle() const
{
	return rectangle;
}

void TypeShoot::SetVelocity(float setVelocity)
{
	velocity = setVelocity;
}

float TypeShoot::GetVelocity() const
{
	return velocity;
}

void TypeShoot::SetDamage(int value)
{
	damage.SetValue(value);
}

int TypeShoot::GetDamage()
{
	return damage.GetValue();
}
