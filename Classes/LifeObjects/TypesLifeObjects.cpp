#include "TypesLifeObjects.h"

using namespace cocos2d;

TypeLifeObject::~TypeLifeObject()
{
}

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

int TypeLifeObject::GetHealth() const
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

void TypeLifeObject::SetAnimationsMove(const CollectionAnimations & animations)
{
	m_moveAnimations = animations;
}

const CollectionAnimations & TypeLifeObject::GetAnimationsMove() const
{
	return m_moveAnimations;
}

void TypeLifeObject::SetId(ID id)
{
	m_id = id;
}

TypeLifeObject::ID TypeLifeObject::GetId() const
{
	return m_id;
}

void TypeLifeObject::SetDeathSounds(std::vector<std::string> & nameSound)
{
	m_nameDeathSound = nameSound;
}

const std::vector<std::string>& TypeLifeObject::GetDeathSounds() const
{
	return m_nameDeathSound;
}

SRange::SRange()
	: start(0.f)
	, end(0.f)
{
}

SRange::SRange(float start, float end)
	: start(start)
	, end(end)
{
}

bool SRange::IsBetween(float value) const
{
	return (start >= value) || (end <= value);
}
