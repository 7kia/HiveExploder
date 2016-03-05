#pragma once

#include "cocos2d.h"



class ManageCircle
{
public:
	enum class Action
	{
		None,
		Attack,
		Move
	};
	const float							RADIUS_MOVE_CIRCLE = 30.f;
	const float							RADIUS_ATTACK_CIRCLE = 20.f;
	const float							RADIUS_CIRCLE = RADIUS_MOVE_CIRCLE + RADIUS_ATTACK_CIRCLE;
public:
	Action								GetAction(cocos2d::Vec2 position);

	void								SetSprite(cocos2d::Sprite*  setSprite);
	cocos2d::Sprite*					GetSprite();

	void								SetPositionX(float x);
	void								SetPositionY(float y);
	void								SetPosition(cocos2d::Vec2 pos);
	float								GetRadius();
	cocos2d::Vec2						GetDirection();
private:
	cocos2d::RefPtr<cocos2d::Sprite>	m_sprite;
	cocos2d::Vec2						m_direction = cocos2d::Vec2::ZERO;
};