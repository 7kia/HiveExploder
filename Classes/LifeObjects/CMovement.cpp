#include "CMovement.h"

CMovement::CMovement()
{
}

CMovement::~CMovement()
{
}

void CMovement::SetVelocity(float setVelocity)
{
	velocity = setVelocity;
}

float CMovement::GetVelocity() const
{
	return velocity;
}
