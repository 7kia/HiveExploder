#include "TypeShoots.h"

using namespace cocos2d;

void ShootType::SetTexture(Texture2D* setTexture)
{
	texture = setTexture;
}

cocos2d::Texture2D * ShootType::GetTexture() const
{
	return texture;
}

void ShootType::SetRect(cocos2d::Rect setRectangle)
{
	rectangle = setRectangle;
}

cocos2d::Rect ShootType::GetRectangle() const
{
	return rectangle;
}

void ShootType::SetVelocity(float setVelocity)
{
	velocity = setVelocity;
}

float ShootType::GetVelocity() const
{
	return velocity;
}

void ShootType::SetDamage(int value)
{
	damage.SetValue(value);
}

int ShootType::GetDamage()
{
	return damage.GetValue();
}
