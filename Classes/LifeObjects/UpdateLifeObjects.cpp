#include "LifeObjects.h"

using namespace cocos2d;

void CLifeObject::update(float dt)
{
	if (GetWeaponState() == CWeapon::IdState::NotActive)
	{
		UpdatePosition(dt);
	}
	else
	{
		SetAttackAnimation();
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
	// TODO : delete
	auto animationCashe = AnimationCache::getInstance();
	auto spriteFrameCashe = SpriteFrameCache::getInstance();
	////

	int idAnimation = GetIndexMoveAnimation(m_direction);
	if (getActionByTag(idAnimation) == nullptr)
	{
		Animate *oldAnimate = GetOldAnimate();

		Animation *animation = m_type->GetAnimationsMove().at(idAnimation);
		Animate *newAnimate = Animate::create(animation);

		newAnimate->setTag(idAnimation);

		if (oldAnimate != nullptr)
		{
			if (oldAnimate->getTag() != newAnimate->getTag())
			{
				newAnimate->setDuration(oldAnimate->getDuration());
			}
		}

		runAction(newAnimate);


	}

}

void CLifeObject::SetAttackAnimation()
{
	// TODO : delete
	auto animationCashe = AnimationCache::getInstance();
	auto spriteFrameCashe = SpriteFrameCache::getInstance();
	////

	int idAnimation = GetIndexMoveAnimation(m_direction);
	if (getActionByTag(idAnimation) == nullptr)
	{
		Animate *oldAnimate = GetOldAnimate();

		Animation *animation = m_type->GetAttackAnimations().at(idAnimation);
		Animate *newAnimate = Animate::create(animation);

		newAnimate->setTag(idAnimation);

		if (oldAnimate != nullptr)
		{
			if (oldAnimate->getTag() != newAnimate->getTag())
			{
				newAnimate->setDuration(oldAnimate->getDuration());
			}
		}

		runAction(newAnimate);


	}

}


Animate * CLifeObject::GetOldAnimate()
{
	Action *oldAnimate;
	for (size_t index = 0; index < rangesDirections.size(); index++)
	{
		oldAnimate = getActionByTag(index);
		if (oldAnimate != nullptr)
		{
			return dynamic_cast<Animate*>(oldAnimate);
		}
	}

	return nullptr;
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