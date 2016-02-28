#pragma once

#include "TypesLifeObjects.h"

// TOOD : CMovement transfer to Behaveour
class CLifeObject : public CMovement
{
public:
	// LifeObjects.cpp
	CLifeObject();
	~CLifeObject();
	void SetType(TypeLifeObject &setType);

	/////////////////
	// MoveLifeobject.cpp
	// \/ class CMovement
	void			Move(cocos2d::Vec2 shiftVector, float dt);

	void			SetVelocity(float setVelocity);
	float			GetVelocity() const;

	void			SetPosition(cocos2d::Vec2 pos);
	void			SetPosition(float x, float y);
	
	float			GetPositionX() const;
	float			GetPositionY() const;
	cocos2d::Vec2	GetPosition() const;
	// /\
	
	void GetCoordinateForView(cocos2d::GLView & view) const;
	/////////////////

	cocos2d::Sprite* GetSprite();
	void SetSprite(cocos2d::Sprite* setSprite);
	

	/////////////////
	// UpdateLifeObject.cpp
	void			Update(float dt);
	void			UpdatePosition(float dt);
	/////////////////

	/////////////////
	// FeaturesLifeObject.cpp
	bool			GetStateDeath() const;
	/////////////////

public:
	CVisual						visual;
private:
	TypeLifeObject				*type;

	bool isDeath = false;// TODO : delete
};
