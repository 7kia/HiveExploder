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
	return m_weapon.GetDamage();
}

void CLifeObject::SetWeapon(const CTypeWeapon & weapon)
{
	m_weapon.SetType(weapon);
}

const CTypeWeapon & CLifeObject::GetWeapon() const
{
	return m_weapon.GetType();
}

TypeLifeObject::ID CLifeObject::GetIdType()
{
	return type->GetId();
}
