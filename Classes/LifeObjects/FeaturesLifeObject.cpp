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

int CLifeObject::GetMaxHealth()
{
	return m_type->GetHealth();
}

int CLifeObject::GetDamage()
{
	return m_weapon.GetDamage();
}

void CLifeObject::SetTypeWeapon(const CTypeWeapon & weapon)
{
	m_weapon.SetType(weapon);
}

const CWeapon & CLifeObject::GetWeapon() const
{
	return m_weapon;
}

void CLifeObject::SetHealthBar(const CBar & bar)
{
	m_healthBar = bar;
}

CBar & CLifeObject::GetHealthBar()
{
	return m_healthBar;
}

TypeLifeObject::ID CLifeObject::GetIdType() const
{
	return m_type->GetId();
}

const TypeLifeObject & CLifeObject::GetType() const
{
	return *m_type;
}

float CLifeObject::GetDistanceWeapon() const
{
	return m_weapon.GetDistance();
}
