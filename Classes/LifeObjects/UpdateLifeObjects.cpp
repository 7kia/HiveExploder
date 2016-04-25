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
	if (m_direction != Vec2::ZERO)
	{
		SetAnimationMove();

		Vec2 resultVector = m_direction;

		resultVector *= m_velocity;
		resultVector *= dt;

		CVisual::Move(resultVector);
		m_direction = Vec2::ZERO;

	}
}

void CLifeObject::SetAnimationMove()
{
	auto animationCashe = AnimationCache::getInstance();
	auto spriteFrameCashe = SpriteFrameCache::getInstance();

	if (getActionByTag(0) == nullptr)
	{
		Animation *animation = m_type->GetAnimationsMove().at(GetIndexMoveAnimation(m_direction));
		Animate *animate = Animate::create(animation);
		animate->setTag(0);
		runAction(animate);
	}
	//setTextureRect(m_type->GetAnimationsMove()[GetIndexMoveAnimation(m_direction)])

}

int CLifeObject::GetIndexMoveAnimation(const Direction & direction)
{
	float rotate = CC_RADIANS_TO_DEGREES(direction.getAngle(VECTOR_VERTICAL_UP));

	for (size_t index = 0; index < rangesDirections.size(); index++)
	{
		if (rangesDirections[index].IsBetween(rotate))
		{
			return index;
		}
	}

	return 0;
}