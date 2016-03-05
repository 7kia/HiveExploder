#pragma once

#include "cocos2d.h"

class CVisual : public cocos2d::Sprite
{
public:
	CVisual();
	virtual ~CVisual() override;

	//CREATE_FUNC(CVisual);
	void			Move(cocos2d::Vec2 shiftVector);	
};
