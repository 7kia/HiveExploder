#pragma once

#include "../Entity/VisualDataType.h"
#include "../Entity/Entity.h"
#include "../Entity/Collision.h"
#include "../Entity/Features.h"
#include "../Entity/Weapon.h"
#include "../HealthBar/HealthBar.h"


struct SRange
{
	SRange();
	SRange(float start, float end);

	bool IsBetween(float value) const;
	float	start = 0;
	float	end = 0;
};

static const std::vector<SRange> rangesDirections = { SRange(67.6f, 112.5f),
													SRange(22.6f, 67.5f),
													SRange(-22.5f, 22.5f),
													SRange(-67.5f, -22.6f),
													SRange(-112.5f, -67.6f),
													SRange(-157.5f, -112.6f),
													SRange(-202.5f, -157.6f),
													SRange(-247.5f, -202.5f) };

class TypeLifeObject :
	public CVisualDataType
{
public:
	~TypeLifeObject();
public:

	enum ID
	{
			None = -1
		,	Player
		,	Zergling
		,	Hydralisk
		,	AmountIDs
	};

	void					SetVelocity(float setVelocity);
	float					GetVelocity() const;

	void					SetHealth(int value);
	int						GetHealth() const;

	int						GetDamage();

	void					SetWeapon(const CTypeWeapon& weapon);
	const CTypeWeapon&		GetTypeWeapon() const;

	void							SetAnimationsMove(const CollectionAnimations & animations);
	const CollectionAnimations &	GetAnimationsMove() const;

	void					SetId(ID id);
	ID						GetId() const;

	void									SetDeathSounds(std::vector<std::string> & nameSound);
	const std::vector<std::string>&				GetDeathSounds() const;

	// TODO : there not enough functional
private:
	float					m_velocity;

	CDynamicFeature			m_health;
	const CTypeWeapon*		m_weapon;
	CollectionAnimations	m_moveAnimations;

	ID						m_id = ID::None;

	std::vector<std::string>				m_nameDeathSound;
};
