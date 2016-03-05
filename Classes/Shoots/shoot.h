#pragma once

#include "TypeShoots.h"

static const float ABOUT_ZERO_VALUE_SPEED_BULLET = 50.f;// if speed less the value shoot delete
static const float COEFFICIENT_SHIFT_BULLET_FROM_SHOOTER = 1.1f;
static const float COEFFECIENT_SLOW_BULLET = 0.01f;

struct CShoot : public CEntity

{
public:
	CShoot();
	//CShoot(const CShoot& copy);
	virtual ~CShoot() override;

	static CShoot* create();
	//CREATE_FUNC(CShoot);

	//bool init() override;
	virtual void cleanup() override;

	void								SetType(ShootType &defineType);
	const ShootType&					GetType();

	void								update(float dt) override;

	void								CreateCollision();

	void								SetDirection(cocos2d::Vec2 directionShooter);
	void								SetStartPlace(cocos2d::Vec2 pos, cocos2d::Vec2 directionShooter,
													cocos2d::Size sizeShooter);
	int									GetDamage(int id);

	//int								GetHealth() const;
	int									GetDamage() ;

private:
	std::shared_ptr<ShootType>			m_type;

	CDynamicFeature						m_damage;
};