#include "../Classes/Config.h"
#include "GameScene.h"
#include "PauseScene.h"
#include "GameOverScene.h"

USING_NS_CC;

Scene* GameScreen::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GameScreen::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameScreen::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    

	// TODO : design
	auto pauseItem = MenuItemImage::create(Buttons::PAUSE_BUTTON,
											Buttons::PAUSE_BUTTON_CLICK,
											CC_CALLBACK_1(GameScreen::GoToGameOverScene, this));

	//- (pauseItem->getContentSize().width / 4)
	pauseItem->setPosition(Point(pauseItem->getContentSize().width / 2  + origin.x,
						visibleSize.height - pauseItem->getContentSize().height + (pauseItem->getContentSize().width / 4) + origin.y));

	auto menu = Menu::create(pauseItem, NULL);
    menu->setPosition(Point::ZERO);
	this->addChild(menu);
	/////////
	for (int i = 0; i < 2; i++)
	{
		backgroundSpriteArray[i] = Sprite::create(GameSceneTexture::BACKGROUND);
		backgroundSpriteArray[i]->setPosition(Point((visibleSize.width / 2), (-1 * visibleSize.height * i) + (visibleSize.height / 2)));
		this->addChild(backgroundSpriteArray[i], -2);
	}

	playerSprite = Sprite::create(GameSceneTexture::SPACE_POD);
	playerSprite->setPosition(Point(visibleSize.width / 2, pauseItem->getPosition().y
								- (pauseItem->getContentSize().height / 2)
								- (playerSprite->getContentSize().height / 2)));

	this->addChild(playerSprite, -1);

	this->scheduleUpdate();

//	this->schedule(schedule_selector(GameScreen::spawnAsteroid), 1.0);

	////////////////////////

    return true;
}

void GameScreen::GoToPauseScene(cocos2d::Ref *pSender)
{
    auto scene = PauseMenu::createScene();
    
	Director::getInstance()->pushScene(scene);
}

void GameScreen::GoToGameOverScene(cocos2d::Ref *pSender)
{
    auto scene = GameOver::createScene();
    
	Director::getInstance()->pushScene(TransitionFade::create(1.0, scene));
}


void GameScreen::update(float dt)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	for (int i = 0; i < 2; i++)
	{
		if (backgroundSpriteArray[i]->getPosition().y >= visibleSize.height + (visibleSize.height / 2) - 1)
		{
			backgroundSpriteArray[i]->setPosition(Point((visibleSize.width / 2) + origin.x, (-1 * visibleSize.height) + (visibleSize.height / 2)));
		}
	}

	for (int i = 0; i < 2; i++)
	{
		backgroundSpriteArray[i]->setPosition(Point(backgroundSpriteArray[i]->getPosition().x, backgroundSpriteArray[i]->getPosition().y + (0.75 * visibleSize.height * dt)));
	}

}
