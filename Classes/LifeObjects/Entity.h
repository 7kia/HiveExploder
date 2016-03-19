#pragma once

#include "CMovement.h"
#include "../Visual/Visual.h"


// TOOD : CMovement transfer to Behaveour
class CEntity : public CMovement, public CVisual
{
public:
	enum class idClass
	{
		None,
		LifeObject,
		Shoot
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