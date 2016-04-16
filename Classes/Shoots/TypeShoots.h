#pragma once

#include "../Entity/VisualDataType.h"
#include "../Entity/Entity.h"
#include "../Entity/Collision.h"
#include "../Entity/Features.h"

static const cocos2d::Vec2 accelerationBullet = { 0.05f, 0.05f };

class CShootType :
	public CVisualDataType
{
public:
	enum ID
	{
		PlayerShoot = 0,
		HydraliskShoot,
		MeleeShoot,
		AmountIDs
	};
};