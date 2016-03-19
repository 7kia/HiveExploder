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
	if (true == isTouching)
	{
		switch (m_manageCirlce.GetAction(touchPosition))
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

void GameScreen::UpdateManageCircle()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	m_manageCirlce.SetPositionX(visibleSize.width / 2 + origin.x);
	m_manageCirlce.SetPositionY(origin.y + m_manageCirlce.GetRadius());
}

void GameScreen::UpdateShoots(float dt)
{
	size_t index = 0;
	while (index < m_shoots.size())
	{
		m_shoots[index]->update(dt);

		if (m_shoots[index]->GetVelocity() < ABOUT_ZERO_VALUE_SPEED_BULLET)
		{
			m_shoots[index]->removeFromParent();

			m_shoots.erase(m_shoots.begin() + index);
		}
		else
		{
			index++;
		}
	}
}

void GameScreen::UpdateLifeObjects(float dt)
{
	size_t index = 0;
	while (index < m_lifeObjects.size())
	{
		m_lifeObjects[index]->update(dt);

		if (m_lifeObjects[index]->GetHealth() < 1)
		{
			m_lifeObjects[index]->removeFromParent();
			m_lifeObjects.erase(m_lifeObjects.begin() + index);
		}
		else
		{
			index++;
		}
	}
}

void GameScreen::AddShoot(CShoot &addShoot)
{
	m_shoots.push_back(&addShoot);
}
