#pragma once

#include "../Entity/VisualDataType.h"
#include "../Entity/SoundDataType.h"

#include "../Entity/Entity.h"

class CEffectType :
	public CVisualDataType
{
public:
	enum ID
	{
			None = 0
		,	MarineShootDeath
		,	MarineDeath
		,	ZerglingDeath
		,	HydraliskShootDeath
		,	HydraliskDeath
		,	GrenadeShootDeath
		,	PlasmaShootDeath			
		,	AmountIDs
	};
public:
	void							SetLifeTime(float time);
	float							GetLifeTime() const;

	void							SetAnimations(const CollectionAnimations & animations);
	const CollectionAnimations &	GetAnimations() const;

private:
	float							m_lifeTime = 0.f;

	CollectionAnimations			m_animations;

};