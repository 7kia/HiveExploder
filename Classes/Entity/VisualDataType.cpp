#include "VisualDataType.h"

using namespace cocos2d;

void CVisualDataType::SetTexture(Texture2D* setTexture)
{
	m_texture = setTexture;
}

cocos2d::Texture2D * CVisualDataType::GetTexture() const
{
	return m_texture;
}

void CVisualDataType::SetTextureRect(cocos2d::Rect setRectangle)
{
	m_rectangle = setRectangle;
}

cocos2d::Rect CVisualDataType::GetTextureRectangle() const
{
	return m_rectangle;
}