#pragma once

#include "Entity.h"

CEntity::CEntity() : CVisual(), CMovement()
{
}

CEntity::~CEntity()
{
}

CEntity * CEntity::create()
{
	CEntity * entity = new(std::nothrow) CEntity;
	if (entity) {
		entity->init();
		entity->autorelease();
		return entity;
	}
	CC_SAFE_DELETE(entity);
	return NULL;
}

CEntity::idClass CEntity::GetIdClass()
{
	return m_idClass;
}

void CEntity::SetIdClass(idClass id)
{
	m_idClass = id;
}

