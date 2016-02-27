#pragma once

#include "cocos2d.h"

typedef cocos2d::Vec2 Direction;

class Movement
{
public:
	virtual void Move(float dt) = 0;
	virtual void Move(cocos2d::Vec2 shiftVector) = 0;

	// TODO : might there not enough functional
private:
	Direction direction;
protected:
	Movement() { }


};
