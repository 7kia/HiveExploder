#include "TypeWeapon.h"


void CTypeWeapon::SetTime(float time)
{
	m_time = time;
}

float CTypeWeapon::GetTime() const
{
	return m_time;
}

void CTypeWeapon::SetVelocity(float setVelocity)
{
	m_velocity = setVelocity;
}

float CTypeWeapon::GetVelocity() const
{
	return m_velocity;
}

void CTypeWeapon::SetDamage(int value)
{
	m_damage.SetValue(value);
}

int CTypeWeapon::GetDamage() const
{
	return m_damage.GetValue();
}

void CTypeWeapon::SetTypeShoot(const CShootType & type)
{
	m_type_shoot = &type;
}

const CShootType* CTypeWeapon::GetTypeShoot() const
{
	return m_type_shoot;
}

void CTypeWeapon::SetId(ID id)
{
	m_id = id;
}

CTypeWeapon::ID CTypeWeapon::GetId() const
{
	return m_id;
}

void CTypeWeapon::SetDistanse(float distance)
{
	m_distance = distance;
}

float CTypeWeapon::GetDistance() const
{
	return m_distance;
}


