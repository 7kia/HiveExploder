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
		//Vec2 posMoveCircle = 
		// check which half of the screen is being touched
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
	}
	///////////////////////
}
