#pragma once

#include "TypesLifeObjects.h"

// TOOD : Movement transfer to Behaveour
class LifeObject
{
public:
	// LifeObjects.cpp
	LifeObject();
	~LifeObject();
	void SetType(TypeLifeObject &setType);

	// class Movement
	void Move(float dt);
	void Move(cocos2d::Vec2 shiftVector);

	// UpdateLifeObject.cpp
	void Update(float dt);
	void UpdatePosition(float dt);

	void									SetVelocity(cocos2d::Vec2 setVelocity);
	void									SetVelocity(float vx , float vy);
	cocos2d::Vec2							GetVelocity() const;

	// FeaturesLifeObject.cpp
	bool									GetStateDeath() const;

	Direction							GetDirectionLook()  const;
	void								SetDirectionLook(const Direction direction);

	/////////////////////////////
	// MoveLifeobject.cpp
	void SetPosition(cocos2d::Vec2 pos);
	void SetPosition(float x, float y);


	float GetPosition(CVisual::IDCoordinate id) const;
	cocos2d::Vec2 GetPosition() const;

	void GetCoordinateForView(cocos2d::GLView & view) const;

	cocos2d::Sprite* GetSprite();
	void SetSprite(cocos2d::Sprite* setSprite);
	/////////////////////////////
public:
	CVisual						visual;
private:
	TypeLifeObject				*type;

	cocos2d::Vec2				velocity;

	Direction direction;

	bool isDeath = false;// TODO : delete
};

