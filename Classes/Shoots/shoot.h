#pragma once
#include "../LifeObjects/CMovement.h"
#include "TypeShoots.h"

const float ABOUT_ZERO_VALUE_SPEED_BULLET = 50.f;// if speed less the value shoot delete
const float COEFFICIENT_SHIFT_BULLET_FROM_SHOOTER = 2.f;


struct CShoot : public CMovement
{
public:
	
	void					SetType(TypeShoot &defineType);
	const TypeShoot&		GetType();

	/////////////////
	// MoveShoot.cpp
	// \/ class CMovement
	void					Move(cocos2d::Vec2 shiftVector, float dt);

	void					SetVelocity(float setVelocity);
	float					GetVelocity() const;

	void					SetPosition(cocos2d::Vec2 pos);
	void					SetPosition(float x, float y);

	float					GetPositionX() const;
	float					GetPositionY() const;
	cocos2d::Vec2			GetPosition() const;
	// /\
	/////////////////

	void					SetSprite(cocos2d::Sprite* setSprite);
	cocos2d::Sprite*		GetSprite();


	void					SetStartPlace(cocos2d::Vec2 pos, cocos2d::Vec2 direction,
											cocos2d::Size sizeShooter);
	int						GetDamage(int id);

private:
	TypeShoot				*type;
	CVisual					visual;

	CDynamicFeature			damage;
};