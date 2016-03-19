#include "TypesLifeObjects.h"

using namespace cocos2d;

void TypeLifeObject::SetTexture(Texture2D* setTexture)
{
	m_texture = setTexture;
}

cocos2d::Texture2D * TypeLifeObject::GetTexture() const
{
	return m_texture;
}

// TODO : rename SetTextureRect
void TypeLifeObject::SetTextureRect(cocos2d::Rect setRectangle)
{
	m_rectangle = setRectangle;
}

cocos2d::Rect TypeLifeObject::GetRectangle() const
{
	return m_rectangle;
}

void TypeLifeObject::SetVelocity(float setVelocity)
{
	m_velocity = setVelocity;
}

float TypeLifeObject::GetVelocity() const
{
	return m_velocity;
}

void TypeLifeObject::SetHealth(int value)
{
	m_health.SetValue(value);
}

int TypeLifeObject::GetHealth()
{
	return m_health.GetValue();
}
