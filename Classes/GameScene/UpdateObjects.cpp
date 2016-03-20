#include "GameScene.h"

using namespace cocos2d;

void GameScreen::UpdateLifeObjects(float dt)
{
	for (auto &object : m_lifeObjects)
	{
		object->update(dt);
	}

	CheckHealthLifeObjects();
	SearchEnemy();// TODO : redefine

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
			if (CheckDefeatCondition(index))
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

void GameScreen::SearchEnemy()// TODO : redefine
{
	Vec2 positionPlayer = m_lifeObjects[m_id_player]->getPosition();
	for (auto &object : m_lifeObjects)
	{
		if (object->GetIdType() != TypeLifeObject::ID::Player)
		{
			Vec2 direction = positionPlayer - object->getPosition();
			direction.normalize();
			object->SetDirection(direction);
		}
	}

}
