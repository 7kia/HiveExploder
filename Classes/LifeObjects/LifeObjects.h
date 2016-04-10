#pragma once

#include "TypesLifeObjects.h"

class GameScreen;
class CShoot;

// TOOD : CMovement transfer to Behaveour
class CLifeObject : public CEntity// public CMovement, public CVisual
{
public:
	// LifeObjects.cpp
	CLifeObject();
	virtual ~CLifeObject() override;

	//virtual void cleanup() override;

	CREATE_FUNC(CLifeObject);
	//CLifeObject* create(const std::string& filename) = delete;

	void SetType(TypeLifeObject &setType);

	void CreateCollision();

	void Move(cocos2d::Vec2 shiftVector, float dt);

	void GetCoordinateForView(cocos2d::GLView & view) const;

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
	int					GetDamage();

	void				SetTypeWeapon(const CTypeWeapon& weapon);
	const CWeapon&		GetWeapon() const;

	TypeLifeObject::ID GetIdType();
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

	/////////////////
public:

	////////
	// TODO : transfer to CWeapon
	float m_timerAttack = 0.f;
	float m_timeReload = 0.05f;
	///////

private:
	TypeLifeObject*					type;

	CDynamicFeature					m_health;
	CWeapon							m_weapon;
	// TODO : delete
};

