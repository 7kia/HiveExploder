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
	virtual ~CEntity();

	static CEntity* create();

	idClass			GetIdClass();
	void			SetIdClass(idClass id);
private:
	idClass m_idClass = idClass::None;
};