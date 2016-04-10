#pragma once

#include "TypeWeapon.h"

class CWeapon
{
public:
	enum class IdState
	{
		NotActive = 0	,
		NotShoot		,
		Shoot
	};

	void					SetType(const CTypeWeapon& type);
	const CTypeWeapon&		GetType() const;

	int						GetDamage() const;
	float					GetVelocity() const;

	void					Update(float dt);
	void					SetState(IdState state);
	IdState					GetState() const;

	float					GetDistance() const;

	const CShootType&		GetTypeShoot() const;

private:
	IdState					m_state = IdState::NotActive;
	float					m_time = 0.f;

	CDynamicFeature			m_damage;
	const CTypeWeapon*		m_type;
};