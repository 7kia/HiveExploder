#pragma once

#include "cocos2d.h"

typedef cocos2d::Vec2 Direction;

static const cocos2d::Vec2 VECTOR_VERTICAL_UP = { 0.f, 1.f };

class CMovement
{
public:
	//virtual void			Move(cocos2d::Vec2 shiftVector, float dt)	= 0;

	void					SetVelocity(float setVelocity);
	float					GetVelocity() const;

	/*
	virtual void			SetPosition(cocos2d::Vec2 pos)				= 0;
	virtual void			SetPosition(float x, float y)				= 0;


	virtual float			GetPositionX() const						= 0;
	virtual float			GetPositionY() const						= 0;
	virtual cocos2d::Vec2	GetPosition() const							= 0;

	*/

	// TODO : might there not enough functional
protected:
	float				velocity;
	Direction			direction;

};
