#include "GameScene.h"

using namespace cocos2d;

void GameScreen::UpdateLifeObjects(float dt)
{
	UpdateCamera(dt);

	CheckHealthLifeObjects();
	SearchEnemy();// TODO : redefine



	//CheckCollisionPlayer(GetPlayer().getPosition());
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

			m_lifeObjects[index]->GetHealthBar().removeFromParent();
			// TODO : incorrect delete &lifeObjects->GetHealthBar().GetSpriteValue()
			
			// TODO : transfer to destructor LifeObject
			PlayRandomSound(m_lifeObjects[index]->GetType().GetDeathSounds());
			//

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

Vec2 GameScreen::GetTileCoordinateForPosition(Vec2 position)
{
	int x = position.x / m_tileMap->getTileSize().width;
	int y = m_tileMap->getMapSize().height * m_tileMap->getTileSize().height;
	y -= position.y;
	y /= m_tileMap->getTileSize().height;

	return Vec2(x, y);
}

// TOOD : mot work
void GameScreen::CheckCollisionPlayer(Vec2 position)
{
	Vec2 tileCoordinate = GetTileCoordinateForPosition(position);
	int tileGid = m_collisionLayer->tileGIDAt(tileCoordinate);
	if (tileGid) {
		Value properties = m_tileMap->propertiesForGID(tileGid);
		//if (properties.) {
			//CCString *collision = new CCString();
			if (properties.asValueMap()["Collision"].asBool()) {
				GetPlayer().setPosition(position);
			}
		//}
	}

}