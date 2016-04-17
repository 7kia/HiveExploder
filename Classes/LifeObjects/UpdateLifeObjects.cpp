#include "LifeObjects.h"

using namespace cocos2d;

void CLifeObject::update(float dt)
{
	if (GetWeaponState() == CWeapon::IdState::NotActive)
	{
		UpdatePosition(dt);
	}

	m_weapon.Update(dt);

	m_healthBar.update(dt);
}


void CLifeObject::UpdatePosition(float dt)
{
	Vec2 resultVector = m_direction;

	resultVector *= m_velocity;
	resultVector *= dt;

	CVisual::Move(resultVector);
	m_direction = Vec2::ZERO;
}
