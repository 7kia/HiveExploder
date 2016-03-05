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

	void SetCollision();

	void Move(cocos2d::Vec2 shiftVector, float dt);

	void GetCoordinateForView(cocos2d::GLView & view) const;

	/////////////////
	// UpdateLifeObject.cpp
	void			update(float dt) override;
	void			UpdatePosition(float dt);
	/////////////////

	/////////////////
	// FeaturesLifeObject.cpp
	bool			GetStateDeath() const;

	void			SetHealth(int value);
	void			AddHealth(int value);
	int				GetHealth() ;
	int				GetDamage() ;

	/////////////////

	/////////////////
	// -.cpp
	// \/ class CWeapon

	void			CreateShoot(GameScreen *scene, cocos2d::Vec2 directionShoot,
								std::vector<CShoot*> &shoots);// TODO : transfer to CWeapon

	/////////////////
	void			Attack();
	/////////////////
public:

	////////
	// TODO : transfer to CWeapon
	float m_timerAttack = 0.f;
	float m_timeReload = 0.05f;
	///////

private:
	TypeLifeObject				*type;

	CDynamicFeature				health;
	CDynamicFeature				m_damage;
	bool isDeath = false;
	// TODO : delete
};

