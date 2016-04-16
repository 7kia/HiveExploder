#include "GameScene.h"

using namespace cocos2d;

void GameScreen::update(float dt)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	UpdateShoots(dt);
	UpdateLifeObjects(dt);
	ActivateActiveWeapons();

	///////////////////////
	// check if the screen is being touched
	if (true == m_isTouching)
	{
		switch (m_manageCirlce.GetAction(m_touchPosition))
		{
		case ManageCircle::Action::Attack:	
			m_lifeObjects[m_id_player]->Attack();
			m_lifeObjects[m_id_player]->SetDirection(m_manageCirlce.GetDirection());
			break;
		case ManageCircle::Action::Move:
			m_lifeObjects[m_id_player]->SetDirection(m_manageCirlce.GetDirection());
			//m_lifeObjects[m_id_player]->SetWeaponState(CWeapon::IdState::NotActive);
			break;
		default:
			m_lifeObjects[m_id_player]->SetWeaponState(CWeapon::IdState::NotActive);
			break;
		}	
		
	}

}

void GameScreen::ActivateActiveWeapons()
{
	for (const auto& lifeObject : m_lifeObjects)
	{
		if (lifeObject->GetWeaponState() == CWeapon::IdState::Shoot)
		{
			lifeObject->CreateShoot(this, lifeObject->GetDirection(), m_shoots);
		}
	}
}

bool GameScreen::onContactBegin(PhysicsContact& contact)
{
	//GoToGameOverScene(this);
	auto bodyA = contact.getShapeA()->getBody();
	auto bodyB = contact.getShapeB()->getBody();
	CCollision* collisionA = static_cast<CCollision*>(bodyA);
	CCollision* collisionB = static_cast<CCollision*>(bodyB);

	CEntity* entityA = collisionA->GetMaster();
	CEntity* entityB = collisionB->GetMaster();

	CEntity::idClass idA = entityA->GetIdClass();
	CEntity::idClass idB = entityB->GetIdClass();

	if ((idA == CEntity::idClass::LifeObject) && (idB == CEntity::idClass::Shoot))
	{
		dynamic_cast<CLifeObject*>(entityA)->AddHealth(-dynamic_cast<CShoot*>(entityB)->GetDamage());
		dynamic_cast<CShoot*>(entityB)->SetVelocity(0.f);

	}
	else if ((idB == CEntity::idClass::LifeObject) && (idA == CEntity::idClass::Shoot))
	{
		dynamic_cast<CLifeObject*>(entityB)->AddHealth(-dynamic_cast<CShoot*>(entityA)->GetDamage());
		dynamic_cast<CShoot*>(entityA)->SetVelocity(0.f);
	}
	//
	

	return true;
}

bool GameScreen::onContactPreSolve(cocos2d::PhysicsContact & contact)
{


	return true;
}


bool GameScreen::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event * event)
{
	m_isTouching = true;

	UpdateTouchPosition(touch);
	return true;
}

void GameScreen::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event * event)
{
	UpdateTouchPosition(touch);
}


void GameScreen::UpdateTouchPosition(cocos2d::Touch *touch)
{
	Point origin = GetPlayer().getPosition();
	origin -= GetMiddleWindow();

	m_touchPosition = touch->getLocation();
	m_touchPosition += origin;

	touch->setTouchInfo(0, m_touchPosition.x, m_touchPosition.y);
}

void GameScreen::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event * event)
{
	UpdateTouchPosition(touch);

	m_isTouching = false;
}

void GameScreen::onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event * event)
{
	onTouchEnded(touch, event);
}

void GameScreen::UpdateManageCircle()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = m_lifeObjects[m_id_player]->getPosition();

	m_manageCirlce.SetPositionX(origin.x);
	m_manageCirlce.SetPositionY(origin.y - visibleSize.height / 2.f + m_manageCirlce.GetRadius());
}

bool GameScreen::CheckVictoryCondition()
{
	if (m_lifeObjects.size() == 1)
	{
		if (m_lifeObjects[0]->GetIdType() == TypeLifeObject::ID::Player)
		{
			return true;
		}
	}
	return false;
}

bool GameScreen::CheckDefeatCondition(size_t index)
{
	if (m_lifeObjects[index]->GetIdType() == TypeLifeObject::ID::Player)
	{
		return true;
	}
	return false;
}

