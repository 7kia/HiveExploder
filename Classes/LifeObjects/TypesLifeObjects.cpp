#include "TypesLifeObjects.h"

using namespace cocos2d;

void TypeLifeObject::SetTexture(Texture2D* setTexture)
{
	texture = setTexture;
}

cocos2d::Texture2D * TypeLifeObject::GetTexture() const
{
	return texture;
}

// TODO : rename SetTextureRect
void TypeLifeObject::SetTextureRect(cocos2d::Rect setRectangle)
{
	rectangle = setRectangle;
}

cocos2d::Rect TypeLifeObject::GetRectangle() const
{
	return rectangle;
}

void TypeLifeObject::SetVelocity(float setVelocity)
{
	velocity = setVelocity;
}

float TypeLifeObject::GetVelocity() const
{
	return velocity;
}

void TypeLifeObject::SetHealth(int value)
{
	health.SetValue(value);
}

int TypeLifeObject::GetHealth()
{
	return health.GetValue();
}
