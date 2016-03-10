#include "LifeObjects.h"



void CLifeObject::SetHealth(int value)
{
	health.SetValue(value);
}

void CLifeObject::AddHealth(int value)
{
	health.SetValue(health.GetValue() + value);
}

int CLifeObject::GetHealth() const
{
	return health.GetValue();
}

int CLifeObject::GetDamage() const
{
	return 0;
}