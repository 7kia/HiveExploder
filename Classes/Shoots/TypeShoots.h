#pragma once
#include "../LifeObjects/Collision.h"
//#include "../Visual/Visual.h"

#include "../LifeObjects/Entity.h"
#include "../LifeObjects/Features.h"

static const cocos2d::Vec2 accelerationBullet = { 0.01f, 0.01f };

class TypeShoot
{
public:
	enum ID
	{
		PlayerShoot = 0,
		HydraliskShoot,
		AmountIDs
	};

public:
	void					SetTexture(cocos2d::Texture2D* setTexture);
	cocos2d::Texture2D*		GetTexture() const;

	void					SetRect(cocos2d::Rect setRectangle);
	cocos2d::Rect			GetRectangle() const;

	void					SetVelocity(float setVelocity);
	float					GetVelocity() const;

	void					SetDamage(int value);
	int						GetDamage();
	// TODO : there not enough functional
private:
	cocos2d::Texture2D*		texture;
	cocos2d::Rect			rectangle;
	float					velocity;
	CDynamicFeature			damage;
};