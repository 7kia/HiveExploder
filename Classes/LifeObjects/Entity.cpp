#pragma once

#include "Entity.h"

using namespace cocos2d;

CEntity::CEntity() : CVisual(), CMovement()
{
}

CEntity::~CEntity()
{
}

void CEntity::Move(cocos2d::Vec2 shiftVector, float dt)
{
	m_direction = shiftVector;
	Vec2 resultVector = m_direction;

	resultVector *= m_velocity;
	resultVector *= dt;

	CVisual::Move(resultVector);
}

CEntity::idClass CEntity::GetIdClass()
{
	return m_idClass;
}

void CEntity::SetIdClass(idClass id)
{
	m_idClass = id;
}

