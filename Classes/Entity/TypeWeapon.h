#pragma once

#include "../Shoots/shoot.h"

class CTypeWeapon
{
public:
	enum ID
	{
		NONE = -1,
		PlayerWeapon = 0,
		HydraliskWeapon	,
		ZerglingWeapon	,
		GrenadeGun		,
		PlasmaGun		,
		AmountIDs
	};

	void					SetTime(float time);
	float					GetTime() const;

	void					SetVelocity(float setVelocity);
	float					GetVelocity() const;

	void					SetDamage(int value);
	int						GetDamage() const;

	void					SetTypeShoot(const CShootType &type);
	const CShootType&		GetTypeShoot() const;

	void					SetId(ID id);
	ID						GetId() const;

	void					SetDistanse(float distance);
	float					GetDistance() const;
private:
	ID						m_id = ID::NONE;

	float					m_time;
	float					m_velocity;
	float					m_distance;
	CDynamicFeature			m_damage;
	const CShootType*		m_type_shoot;
};