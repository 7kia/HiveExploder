#pragma once

#include "../Entity/Entity.h"
#include "../Entity/Collision.h"
#include "../Entity/Features.h"

static const cocos2d::Vec2 accelerationBullet = { 0.05f, 0.05f };

class CShootType
{
public:
	enum ID
	{
		PlayerShoot = 0,
		HydraliskShoot,
		MeleeShoot,
		AmountIDs
	};

public:
	void					SetTexture(cocos2d::Texture2D* setTexture);
	cocos2d::Texture2D*		GetTexture() const;

	void					SetRect(cocos2d::Rect setRectangle);
	cocos2d::Rect			GetRectangle() const;
	// TODO : there not enough functional
private:
	cocos2d::Texture2D*		m_texture;
	cocos2d::Rect			m_rectangle;
};