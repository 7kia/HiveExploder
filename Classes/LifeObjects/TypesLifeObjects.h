#pragma once

#include "../Entity/VisualDataType.h"
#include "../Entity/Entity.h"
#include "../Entity/Collision.h"
#include "../Entity/Features.h"
#include "../Entity/Weapon.h"

class TypeLifeObject :
	public CVisualDataType
{
public:
	enum ID
	{
		None = -1		,
		Player			,
		Zergling		,
		Hydralisk		,
		AmountIDs
	};

	void					SetVelocity(float setVelocity);
	float					GetVelocity() const;

	void					SetHealth(int value);
	int						GetHealth() const;

	int						GetDamage();

	void					SetWeapon(const CTypeWeapon& weapon);
	const CTypeWeapon&		GetTypeWeapon() const;


	void					SetId(ID id);
	ID						GetId() const;
	// TODO : there not enough functional
private:
	float					m_velocity;

	CDynamicFeature			m_health;
	const CTypeWeapon*		m_weapon;

	ID						m_id = ID::None;
};
