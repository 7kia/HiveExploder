#include "TypeBonuses.h"

using namespace cocos2d;

void CBonusesType::SetAction(std::function<void(CLifeObject &)> action)
{
	m_action = action;
}

std::function<void(CLifeObject&)> CBonusesType::GetAction() const
{
	return m_action;
}

void CBonusesType::SetDeathSounds(std::vector<std::string> & nameSound)
{
	m_nameDeathSound = nameSound;
}

const std::vector<std::string> & CBonusesType::GetDeathSounds() const
{
	return m_nameDeathSound;
}

