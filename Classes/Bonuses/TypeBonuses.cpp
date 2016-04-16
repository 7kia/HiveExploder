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

