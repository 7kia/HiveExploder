#include "Movement.h"

CMovement::CMovement()
{
}

CMovement::~CMovement()
{
}

void CMovement::SetVelocity(float setVelocity)
{
	m_velocity = setVelocity;
}

float CMovement::GetVelocity() const
{
	return m_velocity;
}

void CMovement::SetDirection(Direction setDirection)
{
	m_direction = setDirection;
}

Direction CMovement::GetDirection()
{
	return m_direction;
}
