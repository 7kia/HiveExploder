#pragma once
#include "../LifeObjects/CMovement.h"
#include "TypeShoots.h"

static const float ABOUT_ZERO_VALUE_SPEED_BULLET = 50.f;// if speed less the value shoot delete
static const float COEFFICIENT_SHIFT_BULLET_FROM_SHOOTER = 2.f;
static const float COEFFECIENT_SLOW_BULLET = 0.01f;



struct CShoot : public CMovement, public CVisual

{
public:
	CShoot();
	~CShoot();

	static CShoot* create();

	void					SetType(TypeShoot &defineType);
	const TypeShoot&		GetType();

	void					Update(float dt);
	void					Move(cocos2d::Vec2 shiftVector, float dt);


	void					SetCollision();

	void SetRotation(cocos2d::Vec2 directionShooter);

	void					SetStartPlace(cocos2d::Vec2 pos, cocos2d::Vec2 directionShooter,
											cocos2d::Size sizeShooter);
	int						GetDamage(int id);

private:
	TypeShoot				*type;

	CDynamicFeature			damage;
};