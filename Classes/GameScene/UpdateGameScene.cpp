#include "GameScene.h"

using namespace cocos2d;

void GameScreen::update(float dt)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();


	///////////////////////
	// check if the screen is being touched
	if (true == isTouching)
	{
		/*
				if (manageCirlce.GetAction(touchPosition) == ManageCircle::Action::Attack)
		{
			CShoot addShoot;
			auto sprite = Sprite::create();
			addShoot.SetSprite(sprite);
			///*
			addShoot.SetType(this->typesShoots[TypeShoot::PlayerShoot]);
			addShoot.SetStartPlace(this->lifeObjects[0].GetPosition(), this->manageCirlce.GetDirection(),
				this->lifeObjects[0].GetSprite()->getContentSize());

			shoots.push_back(addShoot);
			this->addChild(sprite);

		}
		*/


		switch (manageCirlce.GetAction(touchPosition))
		{
		case ManageCircle::Action::Attack:
			
			lifeObjects[0].CreateShoot(this, shoots);


			//*/


			break;
		case ManageCircle::Action::Move:
			
				// move the space pod left
				//playerSprite->setPositionX(playerSprite->getPosition().x - (0.50 * visibleSize.width * dt));
				lifeObjects[0].Move(manageCirlce.GetDirection(), dt);


				/*
								// check to prevent the space pod from going off the screen (left side)
				if (playerSprite->getPosition().x <= 0 + (playerSprite->getContentSize().width / 2))
				{
					playerSprite->setPositionX(playerSprite->getContentSize().width / 2);
				}
				*/

			
			break;
		default:
			break;
		}
		/*
				if (touchPosition.x < visibleSize.width / 2)
		{
			// move the space pod left
			playerSprite->setPositionX(playerSprite->getPosition().x - (0.50 * visibleSize.width * dt));
			

			// check to prevent the space pod from going off the screen (left side)
			if (playerSprite->getPosition().x <= 0 + (playerSprite->getContentSize().width / 2))
			{
				playerSprite->setPositionX(playerSprite->getContentSize().width / 2);
			}
		}
		else
		{
			// move the space pod right
			playerSprite->setPositionX(playerSprite->getPosition().x + (0.50 * visibleSize.width * dt));

			// check to prevent the space pod from going off the screen (right side)
			if (playerSprite->getPosition().x >= visibleSize.width - (playerSprite->getContentSize().width / 2))
			{
				playerSprite->setPositionX(visibleSize.width - (playerSprite->getContentSize().width / 2));
			}
		}

		*/
		//Vec2 posMoveCircle = 
		// check which half of the screen is being touched
	}
	///////////////////////
}

void GameScreen::UpdateManageCircle()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	manageCirlce.SetPositionX(visibleSize.width / 2 + origin.x);
	manageCirlce.SetPositionY(origin.y + manageCirlce.GetRadius());
}

void GameScreen::AddShoot(const CShoot & addShoot)
{
	shoots.push_back(addShoot);
}
