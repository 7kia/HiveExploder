#pragma once

#include "TypesLifeObjects.h"

class GameScreen;
class CShoot;
class CBar;

// TOOD : CMovement transfer to Behaveour
class CLifeObject : 
	public CEntity// public CMovement, public CVisual
{
public:
	// LifeObjects.cpp
	CLifeObject();
	virtual ~CLifeObject() override;

	//virtual void cleanup() override;

	CREATE_FUNC(CLifeObject);
	//CLifeObject* create(const std::string& filename) = delete;

	void				SetType(TypeLifeObject &setType);

	void				CreateCollision();

	void				Move(cocos2d::Vec2 shiftVector, float dt);

	void				GetCoordinateForView(cocos2d::GLView & view) const;// TODO : camera

	/////////////////
	// UpdateLifeObject.cpp
	void			update(float dt) override;
	void			UpdatePosition(float dt);
	/////////////////

	/////////////////
	// FeaturesLifeObject.cpp
	void				SetHealth(int value);
	void				AddHealth(int value);

	int					GetHealth();
	int					GetMaxHealth();

	int					GetDamage();

	void				SetTypeWeapon(const CTypeWeapon& weapon);
	const CWeapon&		GetWeapon() const;

	void				SetHealthBar(const CBar &bar);
	CBar &				GetHealthBar();

	float				GetDistanceWeapon() const;

	TypeLifeObject::ID	GetIdType() const;
	/////////////////

	/////////////////
	// -.cpp
	// \/ class CWeapon

	void			CreateShoot(GameScreen *scene, cocos2d::Vec2 directionShoot,
								std::vector<CShoot*> &shoots);// TODO : transfer to CWeapon

	/////////////////
	void					Attack();
	void					SetWeaponState(CWeapon::IdState state);
	CWeapon::IdState		GetWeaponState() const;

	void					SetWeapon(const CTypeWeapon & typeWeapon);
	/////////////////
public:

	////////
	// TODO : transfer to CWeapon
	float m_timerAttack = 0.f;
	float m_timeReload = 0.05f;
	///////

private:
	std::shared_ptr<const TypeLifeObject>					m_type;//TypeLifeObject

	CDynamicFeature					m_health;
	CWeapon							m_weapon;
	CBar							m_healthBar;
	// TODO : delete
};

