#include "TypeEffect.h"

using namespace cocos2d;

void CEffectType::SetLifeTime(float time)
{
	m_lifeTime = time;
}

float CEffectType::GetLifeTime() const
{
	return m_lifeTime;
}

void CEffectType::SetAnimations(const CollectionAnimations & animations)
{
	m_animations = animations;
}

const CollectionAnimations & CEffectType::GetAnimations() const
{
	return m_animations;
}
