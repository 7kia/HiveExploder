#pragma once

#include "Movement.h"
#include "Collision.h"
#include "../Visual/Visual.h"
#include "VisualDataType.h"

// TOOD : CMovement transfer to Behaveour
class CEntity : public CMovement, public CVisual
{
public:
	enum class idClass
	{
			None = 0
		,	LifeObject
		,	Shoot
		,	Bonus
		,	Effect
		,	Obstacle	
		,	HealthBar
	};
public:
	CEntity();
	virtual ~CEntity() override;

	CREATE_FUNC(CEntity);

	void			Move(cocos2d::Vec2 shiftVector, float dt);

	idClass			GetIdClass();
	void			SetIdClass(idClass id);

private:
	idClass			m_idClass = idClass::None;
};