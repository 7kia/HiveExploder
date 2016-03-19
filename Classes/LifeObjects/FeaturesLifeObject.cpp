#include "LifeObjects.h"

void CLifeObject::SetHealth(int value)
{
	m_health.SetValue(value);
}

void CLifeObject::AddHealth(int value)
{
	m_health.AddToValue(value);
}

int CLifeObject::GetHealth()
{
	return m_health.GetValue();
}

int CLifeObject::GetDamage()
{
	return m_damage.GetValue();
}

TypeLifeObject::ID CLifeObject::GetIdType()
{
	return type->GetId();
}
