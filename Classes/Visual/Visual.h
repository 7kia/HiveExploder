#pragma once

// TODO : delete if will not need
//#include <SFML/Graphics/RenderWindow.hpp>
//#include <SFML/Graphics.hpp>
#include "cocos2d.h"
//#include "../StructGame/ResourceIdentifiers.h"

class CVisual
{
public:
	void			SetTexture(cocos2d::Texture2D* texture);
	void			SetTextureRect(cocos2d::Rect rectangle);
	cocos2d::Rect	GetGlobalBounds() const;
	void			SetOrigin(cocos2d::Vec2 setOrigin);

	void			Move(cocos2d::Vec2 shiftVector);

	void			SetPosition(cocos2d::Vec2 pos);
	void			SetPosition(float x, float y);

	float			GetPositionX() const;
	float			GetPositionY() const;
	cocos2d::Vec2	GetPosition() const;
	

	cocos2d::Sprite* GetSprite();
	void SetSprite(cocos2d::Sprite* setSprite);

public:// TODO : will do private
	cocos2d::Sprite* sprite;
};
