#include "UpdateEffects.h"

using namespace cocos2d;

void GameScreen::UpdateEffects(float dt)
{
	for (auto &effect : m_effects)
	{
		effect->update(dt);
	}

	CheckStateEffects();
}

void GameScreen::CheckStateEffects()
{
	size_t index = 0;// TODO : remove_if
	while (index < m_effects.size())
	{
		if (m_effects[index]->GetState() == CEffect::State::Death)
		{
			m_effects[index]->removeFromParent();
			m_effects.erase(m_effects.begin() + index);
		}
		else
		{
			index++;
		}
	}
}

