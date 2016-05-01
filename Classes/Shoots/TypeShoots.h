#pragma once

#include "../Entity/VisualDataType.h"
#include "../Entity/SoundDataType.h"
#include "../Entity/HaveDeathEffect.h"

#include "../Entity/Entity.h"
#include "../Entity/Collision.h"
#include "../Entity/Features.h"

static const cocos2d::Vec2 accelerationBullet = { 0.05f, 0.05f };

class CShootType :
		public CVisualDataType
	,	public CHaveDeathEffect
{
public:
	enum ID
	{
			MarineShoot = 0	
		,	HydraliskShoot
		,	MeleeShoot
		,	Grenade
		,	Plasma			
		,	AmountIDs
	};
};