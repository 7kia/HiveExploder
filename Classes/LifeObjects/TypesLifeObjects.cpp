#include "TypesLifeObjects.h"

using namespace cocos2d;

void TypeLifeObject::SetVelocity(float setVelocity)
{
	m_velocity = setVelocity;
}

float TypeLifeObject::GetVelocity() const
{
	return m_velocity;
}

void TypeLifeObject::SetHealth(int value)
{
	m_health.SetValue(value);
}

int TypeLifeObject::GetHealth()
{
	return m_health.GetValue();
}

int TypeLifeObject::GetDamage()
{
	return m_weapon->GetDamage();
}

void TypeLifeObject::SetWeapon(const CTypeWeapon & weapon)
{
	m_weapon = &weapon;
}

const CTypeWeapon & TypeLifeObject::GetTypeWeapon() const
{
	return *m_weapon;
}

void TypeLifeObject::SetId(ID id)
{
	m_id = id;
}

TypeLifeObject::ID TypeLifeObject::GetId()
{
	return m_id;
}
