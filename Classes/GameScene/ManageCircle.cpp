#include "ManageCircle.h"

using namespace cocos2d;

ManageCircle::Action ManageCircle::GetAction(cocos2d::Vec2 position)
{
	Vec2 posCircle = sprite->getPosition();

	float distanse = posCircle.getDistance(position);

	if (distanse < RADIUS_MOVE_CIRCLE)
	{
		direction = position - posCircle;
		direction.normalize();
		return Action::Move;
	}
	else if (distanse < (RADIUS_MOVE_CIRCLE + RADIUS_ATTACK_CIRCLE))
	{
		direction = position - posCircle;
		direction.normalize();
		return Action::Attack;
	}
	else
	{
		direction = { 0.f, 0.f };
		return Action::None;
	}
}

void ManageCircle::SetSprite(std::shared_ptr<cocos2d::Sprite> setSprite)
{
	sprite = setSprite;
}

std::shared_ptr<cocos2d::Sprite>  ManageCircle::GetSprite()
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

cocos2d::Vec2 ManageCircle::GetDirection()
{
	return direction;
}
