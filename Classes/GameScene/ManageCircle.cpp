#include "ManageCircle.h"

using namespace cocos2d;

ManageCircle::Action ManageCircle::GetAction(cocos2d::Vec2 position)
{
	Vec2 posCircle = sprite->getPosition();
	//posCircle += Vec2(RADIUS_CIRCLE, RADIUS_CIRCLE);

	float distanse = posCircle.getDistance(position);

	if (distanse < RADIUS_MOVE_CIRCLE)
	{
		return Action::Move;
	}
	else if (distanse < (RADIUS_MOVE_CIRCLE + RADIUS_ATTACK_CIRCLE))
	{
		return Action::Attack;
	}
	else
	{
		return Action::None;
	}
}

void ManageCircle::SetSprite(Sprite *setSprite)
{
	sprite = setSprite;
}

cocos2d::Sprite* ManageCircle::GetSprite()
{
	return sprite;
}

void ManageCircle::SetPositionX(float x)
{
	sprite->setPositionX(x);
}

void ManageCircle::SetPositionY(float y)
{
	sprite->setPositionY(y);
}

void ManageCircle::SetPosition(cocos2d::Vec2 pos)
{
	sprite->setPosition(pos);
}

float ManageCircle::GetRadius()
{
	return RADIUS_CIRCLE;
}
