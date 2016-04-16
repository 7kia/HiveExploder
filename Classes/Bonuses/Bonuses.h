#pragma once

#include "TypeBonuses.h"

class CBonus: public CEntity
{
public:
	CBonus();
	//CShoot(const CShoot& copy);
	virtual ~CBonus() override;

	static CBonus* create();
	//CREATE_FUNC(CShoot);

	//bool init() override;
	virtual void cleanup() override;

	void								SetType(const CBonusesType &defineType);
	const CBonusesType&					GetType();

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