#include "GameScene.h"

using namespace cocos2d;

void GameScreen::UpdateLifeObjects(float dt)
{
	UpdateCamera(dt);

	CheckHealthLifeObjects();
	SearchEnemy();// TODO : redefine


	for (auto &object : m_lifeObjects)
	{
		object->update(dt);
	}


	if (CheckVictoryCondition())
	{
		GoToVictoryScene(this);
	}

}

void GameScreen::UpdateCamera(float dt)
{
	Vec2 positionPlayer = m_lifeObjects[m_id_player]->getPosition();
	Direction directtionPlayer = m_lifeObjects[m_id_player]->GetDirection();
	Vec2 shift = directtionPlayer * dt;

	// TODO : redesign
	m_camera->setPosition(positionPlayer + shift);

	getChildByName("menu")->setPosition(getChildByName("menu")->getPosition() + shift);
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
	Vec2 ownPosition;
	for (auto &object : m_lifeObjects)
	{
		if (object->GetIdType() != TypeLifeObject::ID::Player)
		{
			ownPosition = object->getPosition();
			Vec2 direction = positionPlayer - ownPosition;
			float distanse = positionPlayer.getDistance(ownPosition);


			float distanceAttack = object->GetDistanceWeapon();
			direction.normalize();
			object->SetDirection(direction);

			if (distanse < distanceAttack)
			{
				object->Attack();
			}
			else
			{
				object->SetWeaponState(CWeapon::IdState::NotActive);
			}
		
		}
	}

}
