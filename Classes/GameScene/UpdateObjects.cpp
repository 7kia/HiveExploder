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
	Vec2 positionPlayer = GetPlayer().getPosition();
	Direction directtionPlayer = GetPlayer().GetDirection();

	Director::getInstance()->getRunningScene()->getDefaultCamera()->setPosition(positionPlayer);

	UpdateManageCircle();

	cocos2d::Node* menu = getChildByName("menu");
	menu->setPosition(positionPlayer - GetMiddleWindow());
}

Camera & GameScreen::GetCamera()
{
	return *Director::getInstance()->getRunningScene()->getDefaultCamera();
}

void GameScreen::ResetCamera()
{
	GetCamera().setPosition(Vec2::ZERO);
}

void GameScreen::CheckHealthLifeObjects()
{
	size_t index = 0;// TODO : remove_if
	while (index < m_lifeObjects.size())
	{
		if (m_lifeObjects[index]->GetHealth() < 1)
		{
			if (CheckDefeatCondition(index))
			{
				ResetCamera();// TODO : remove_if
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
	Vec2 positionPlayer = GetPlayer().getPosition();
	for (auto &object : m_lifeObjects)
	{
		if (object->GetIdType() != TypeLifeObject::ID::Player)
		{
			DefineDirectionToEnemyForObject(object, positionPlayer);
			DefineNeedAttackEnemy(object, positionPlayer);	
		}
	}

}

void GameScreen::DefineDirectionToEnemyForObject(CLifeObject * object, const Vec2 & positionEnemy)
{
	Vec2 direction = positionEnemy - object->getPosition();

	direction.normalize();
	object->SetDirection(direction);
}

void GameScreen::DefineNeedAttackEnemy(CLifeObject * object, const Vec2 & positionEnemy)
{
	float distanse = positionEnemy.getDistance(object->getPosition());
	float distanceAttack = object->GetDistanceWeapon();

	if (distanse < distanceAttack)
	{
		object->Attack();
	}
	else
	{
		object->SetWeaponState(CWeapon::IdState::NotActive);
	}
}
