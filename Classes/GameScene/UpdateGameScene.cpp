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
		switch (manageCirlce.GetAction(touchPosition))
		{

		case ManageCircle::Action::Attack:	
			if (lifeObjects[0]->timerAttack == 0.f)
			{
				lifeObjects[0]->CreateShoot(this, manageCirlce.GetDirection(), shoots);
			}
			break;
		case ManageCircle::Action::Move:
			lifeObjects[0]->Move(manageCirlce.GetDirection(), dt);
			break;
		default:
			break;
		}	

		if (lifeObjects[0]->timerAttack < lifeObjects[0]->timeReload)
		{
			lifeObjects[0]->timerAttack += dt;// CWeapon
		}
		else
		{
			lifeObjects[0]->timerAttack = 0.f;// CWeapon
		}
	}
}

void GameScreen::UpdateManageCircle()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	manageCirlce.SetPositionX(visibleSize.width / 2 + origin.x);
	manageCirlce.SetPositionY(origin.y + manageCirlce.GetRadius());
}

void GameScreen::UpdateShoots(float dt)
{
	size_t index = 0;
	while (index < shoots.size())
	{
		shoots[index]->Update(dt);

		if (shoots[index]->GetVelocity() < ABOUT_ZERO_VALUE_SPEED_BULLET)
		{
			//removeChild(shoots[index]);
			shoots[index]->removeFromParentAndCleanup(true);

			shoots.erase(shoots.begin() + index);
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
	while (index < lifeObjects.size())
	{
		lifeObjects[index]->Update(dt);

		if (lifeObjects[index]->GetHealth() < 1)
		{
			lifeObjects[index]->removeFromParentAndCleanup(true);

			lifeObjects.erase(lifeObjects.begin() + index);
		}
		else
		{
			index++;
		}
	}
}

void GameScreen::AddShoot(CShoot *const addShoot)
{
	shoots.push_back(addShoot);
}
