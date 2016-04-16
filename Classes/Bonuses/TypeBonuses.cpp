#include "TypeBonuses.h"

using namespace cocos2d;

void CBonusesType::SetAction(std::function<void(CLifeObject & master)> action)
{
	m_action = action;
}
