#pragma once

#include "TypesLifeObjects.h"

class GameScreen;
class CShoot;

// TOOD : CMovement transfer to Behaveour
class CLifeObject : public CMovement, public CVisual
{
public:
	// LifeObjects.cpp
	CLifeObject();
	~CLifeObject();

	static CLifeObject* create();
	//CLifeObject* create(const std::string& filename) = delete;

	void SetType(TypeLifeObject &setType);

	void SetCollision();

	void Move(cocos2d::Vec2 shiftVector, float dt);

	void GetCoordinateForView(cocos2d::GLView & view) const;
<<<<<<< dev
	/////////////////

	std::shared_ptr<cocos2d::Sprite>  GetSprite();
	void SetSprite(std::shared_ptr<cocos2d::Sprite>  setSprite);
	
=======
>>>>>>> local

	/////////////////
	// UpdateLifeObject.cpp
	void			Update(float dt);
	void			UpdatePosition(float dt);
	/////////////////

	/////////////////
	// FeaturesLifeObject.cpp
	bool			GetStateDeath() const;
	/////////////////

	/////////////////
	// -.cpp
	// \/ class CWeapon
<<<<<<< dev
	void			CreateShoot(GameScreen *scene, std::vector<CShoot> &shoots);// TODO : transfer to CWeapon
=======
	void			CreateShoot(GameScreen *scene, cocos2d::Vec2 directionShoot,
								std::vector<CShoot*> &shoots);// TODO : transfer to CWeapon
>>>>>>> local
	/////////////////
	void			Attack();
	/////////////////
public:
<<<<<<< dev
	CVisual						visual;
=======
	////////
	// TODO : transfer to CWeapon
	float timerAttack = 0.f;
	float timeReload = 0.05f;
	///////
>>>>>>> local
private:
	TypeLifeObject				*type;

	CDynamicFeature				health;

	bool isDeath = false;
	// TODO : delete
};

