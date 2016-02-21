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

	pauseItem->setPosition(Point(pauseItem->getContentSize().width - (pauseItem->getContentSize().width / 4) + origin.x,
						visibleSize.height - pauseItem->getContentSize().height + (pauseItem->getContentSize().width / 4) + origin.y));

	auto menu = Menu::create(pauseItem, NULL);
	menu->alignItemsVerticallyWithPadding(visibleSize.height / 4);
	this->addChild(menu);
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
    
    Director::getInstance()->replaceScene(scene);
}
