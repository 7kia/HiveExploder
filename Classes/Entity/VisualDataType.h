#pragma once

#include "cocos2d.h"

typedef std::vector<cocos2d::Animate *> CollectionAnimations;

class CVisualDataType
{
public:
	void					SetTexture(cocos2d::Texture2D* setTexture);
	cocos2d::Texture2D*		GetTexture() const;

	void					SetTextureRect(cocos2d::Rect setRectangle);
	cocos2d::Rect			GetTextureRectangle() const;
	// TODO : there not enough functional
private:
	cocos2d::Texture2D*		m_texture;
	cocos2d::Rect			m_rectangle;
};