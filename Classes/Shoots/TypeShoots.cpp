#include "TypeShoots.h"

using namespace cocos2d;

void ShootType::SetTexture(Texture2D* setTexture)
{
	m_texture = setTexture;
}

cocos2d::Texture2D * ShootType::GetTexture() const
{
	return m_texture;
}

void ShootType::SetRect(cocos2d::Rect setRectangle)
{
	m_rectangle = setRectangle;
}

cocos2d::Rect ShootType::GetRectangle() const
{
	return m_rectangle;
}

void ShootType::SetVelocity(float setVelocity)
{
	m_velocity = setVelocity;
}

float ShootType::GetVelocity() const
{
	return m_velocity;
}

void ShootType::SetDamage(int value)
{
	m_damage.SetValue(value);
}

int ShootType::GetDamage()
{
	return m_damage.GetValue();
}
