#include "TypeShoots.h"

using namespace cocos2d;

void CShootType::SetTexture(Texture2D* setTexture)
{
	m_texture = setTexture;
}

cocos2d::Texture2D * CShootType::GetTexture() const
{
	return m_texture;
}

void CShootType::SetRect(cocos2d::Rect setRectangle)
{
	m_rectangle = setRectangle;
}

cocos2d::Rect CShootType::GetRectangle() const
{
	return m_rectangle;
}