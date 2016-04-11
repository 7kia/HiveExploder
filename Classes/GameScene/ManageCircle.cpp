#include "ManageCircle.h"

using namespace cocos2d;

ManageCircle::Action ManageCircle::GetAction(cocos2d::Vec2 position)
{
	Vec2 posCircle = m_sprite->getPosition();

	float distanse = posCircle.getDistance(position);

	if (distanse < RADIUS_MOVE_CIRCLE)
	{
		m_direction = position - posCircle;
		m_direction.normalize();
		return Action::Move;
	}
	else if (distanse < (RADIUS_MOVE_CIRCLE + RADIUS_ATTACK_CIRCLE))
	{
		m_direction = position - posCircle;
		m_direction.normalize();
		return Action::Attack;
	}
	else
	{
		m_direction = { 0.f, 0.f };
		return Action::None;
	}
}

void ManageCircle::SetSprite(Sprite *setSprite)
{
	m_sprite = setSprite;
}

cocos2d::Sprite* ManageCircle::GetSprite()
{
	return m_sprite;
}

void ManageCircle::SetPositionX(float x)
{
	m_sprite->setPositionX(x);
}

void ManageCircle::SetPositionY(float y)
{
	m_sprite->setPositionY(y);
}

void ManageCircle::SetPosition(cocos2d::Vec2 pos)
{
	m_sprite->setPosition(pos);
}

cocos2d::Vec2 ManageCircle::GetPosition() const
{
	return m_sprite->getPosition();
}

float ManageCircle::GetRadius()
{
	return RADIUS_CIRCLE;
}

cocos2d::Vec2 ManageCircle::GetDirection()
{
	return m_direction;
}
