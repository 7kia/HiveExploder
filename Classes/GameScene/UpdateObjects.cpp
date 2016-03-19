#include "GameScene.h"

using namespace cocos2d;

void GameScreen::UpdateLifeObjects(float dt)
{
	for (auto &object : m_lifeObjects)
	{
		object->update(dt);
	}

	CheckHealthLifeObjects();

	if (CheckVictoryCondition())
	{
		GoToVictoryScene(this);
	}
}

void GameScreen::CheckHealthLifeObjects()
{
	size_t index = 0;
	while (index < m_lifeObjects.size())
	{
		if (m_lifeObjects[index]->GetHealth() < 1)
		{
			if (CheckDefeatCondition())
			{
				GoToGameOverScene(this);
			}

			m_lifeObjects[index]->removeFromParent();
			m_lifeObjects.erase(m_lifeObjects.begin() + index);
		}
		else
		{
			index++;
		}
	}
}
