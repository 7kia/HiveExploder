#pragma once

#include "cocos2d.h"

typedef cocos2d::Vec2 Direction;

static const cocos2d::Vec2 VECTOR_VERTICAL_UP = { 0.f, 1.f };

class CMovement
{
public:
	CMovement();
	virtual ~CMovement();

	void					SetVelocity(float setVelocity);
	float					GetVelocity() const;

	void					SetDirection(Direction setDirection);
	Direction				GetDirection();
	// TODO : might there not enough functional
protected:
	float					m_velocity;
	Direction				m_direction;

};
