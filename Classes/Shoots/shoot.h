#pragma once

#include "TypeShoots.h"

static const float ABOUT_ZERO_VALUE_SPEED_BULLET = 150.f;// if speed less the value shoot delete
static const float COEFFICIENT_SHIFT_BULLET_FROM_SHOOTER = 1.3f;
static const float COEFFECIENT_SLOW_BULLET = 0.02f;

class CWeapon;

class CShoot :
		public CEntity 
{
public:
	CShoot();
	//CShoot(const CShoot& copy);
	virtual ~CShoot() override;

	static CShoot* create();
	//CREATE_FUNC(CShoot);

	//bool init() override;
	virtual void cleanup() override;

	void								SetType(const CShootType &defineType);
	const CShootType&					GetType();

	void								update(float dt) override;

	void								CreateCollision();

	void								SetDirection(cocos2d::Vec2 directionShooter);
	void								SetStartPlace(cocos2d::Vec2 pos, cocos2d::Vec2 directionShooter,
													cocos2d::Size sizeShooter);
	int									GetDamage(int id);

	int									GetDamage();

	void								SetWeapon(const CWeapon & weapon);
	const CWeapon*						GetWeapon() const;
private:
	std::shared_ptr<const CShootType>	m_type;
	CDynamicFeature						m_damage;
	const CWeapon*						m_weapon;
};