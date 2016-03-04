#include "GameScene.h"

using namespace cocos2d;

void GameScreen::update(float dt)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	UpdateShoots(dt);
	///////////////////////
	// check if the screen is being touched
	if (true == isTouching)
	{
		switch (manageCirlce.GetAction(touchPosition))
		{
		case ManageCircle::Action::Attack:	
			lifeObjects[0].CreateShoot(this, manageCirlce.GetDirection(), shoots);
			break;
		case ManageCircle::Action::Move:
			lifeObjects[0].Move(manageCirlce.GetDirection(), dt);		
			break;
		default:
			break;
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
		shoots[index].Update(dt);

		if (shoots[index].GetVelocity() < ABOUT_ZERO_VALUE_SPEED_BULLET)
		{
			shoots.erase(shoots.begin() + index);
		}
		else
		{
			index++;
		}
	}
}

void GameScreen::AddShoot(const CShoot & addShoot)
{
	shoots.push_back(addShoot);
}
