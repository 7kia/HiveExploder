#include "GameScene.h"

using namespace cocos2d;

void GameScreen::update(float dt)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	UpdateShoots(dt);
	UpdateLifeObjects(dt);
	///////////////////////
	// check if the screen is being touched
	if (true == m_isTouching)
	{
		switch (m_manageCirlce.GetAction(m_touchPosition))
		{
		case ManageCircle::Action::Attack:	

			if (m_lifeObjects[0]->m_timerAttack == 0.f)
			{
				m_lifeObjects[0]->CreateShoot(this, m_manageCirlce.GetDirection(), m_shoots);
			}
			break;
		case ManageCircle::Action::Move:
			//lifeObjects[0]->Move(manageCirlce.GetDirection(), dt);
			m_lifeObjects[0]->SetDirection(m_manageCirlce.GetDirection());

			break;
		default:
			break;
		}	


		if (m_lifeObjects[0]->m_timerAttack < m_lifeObjects[0]->m_timeReload)
		{
			m_lifeObjects[0]->m_timerAttack += dt;// CWeapon
		}
		else
		{
			m_lifeObjects[0]->m_timerAttack = 0.f;// CWeapon
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
	auto bodyA = contact.getShapeA()->getBody();
	auto bodyB = contact.getShapeB()->getBody();
	CCollision* collisionA = static_cast<CCollision*>(bodyA);
	CCollision* collisionB = static_cast<CCollision*>(bodyB);

	CEntity* entityA = collisionA->GetMaster();
	CEntity* entityB = collisionB->GetMaster();

	CEntity::idClass idA = entityA->GetIdClass();
	CEntity::idClass idB = entityB->GetIdClass();

	if ((idA == CEntity::idClass::LifeObject) && (idB == CEntity::idClass::LifeObject))
	{
		if ((dynamic_cast<CLifeObject*>(entityA)->GetIdType() == TypeLifeObject::ID::Player)
			&& (dynamic_cast<CLifeObject*>(entityB)->GetIdType() == TypeLifeObject::ID::Zergling))
		{
			dynamic_cast<CLifeObject*>(entityA)->AddHealth(-dynamic_cast<CLifeObject*>(entityB)->GetDamage());
		}
		else if ((dynamic_cast<CLifeObject*>(entityA)->GetIdType() == TypeLifeObject::ID::Zergling)
			&& (dynamic_cast<CLifeObject*>(entityB)->GetIdType() == TypeLifeObject::ID::Player))
		{
			dynamic_cast<CLifeObject*>(entityB)->AddHealth(-dynamic_cast<CLifeObject*>(entityA)->GetDamage());
		}
	}

	return true;
}


bool GameScreen::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event * event)
{
	m_isTouching = true;
	m_touchPosition = touch->getLocation();

	return true;
}

void GameScreen::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event * event)
{
	m_touchPosition = touch->getLocation();
}

void GameScreen::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event * event)
{
	m_isTouching = false;
}

void GameScreen::onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event * event)
{
	onTouchEnded(touch, event);
}

void GameScreen::UpdateManageCircle()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	m_manageCirlce.SetPositionX(visibleSize.width / 2 + origin.x);
	m_manageCirlce.SetPositionY(origin.y + m_manageCirlce.GetRadius());
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
