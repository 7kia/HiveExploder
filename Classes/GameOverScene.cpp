#include "../Classes/Config.h"
#include "GameOverScene.h"
#include "GameScene.h"
#include "MainMenuScene.h"

USING_NS_CC;

Scene* GameOver::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GameOver::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameOver::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    
	/////////////////////
	// TODO : design
	auto menuTitle = MenuItemImage::create(GAMEOVER_SCREEN_MENU_TITLE,
											GAMEOVER_SCREEN_MENU_TITLE);

	auto retryItem = MenuItemImage::create(GAMEOVER_RETRY_BUTTON,
											GAMEOVER_RETRY_BUTTON_CLICK,
											CC_CALLBACK_1(GameOver::GoToGameScene, this));

	auto mainMenuItem = MenuItemImage::create(GAMEOVER_MENU_BUTTON,
												GAMEOVER_MENU_BUTTON_CLICK,
												CC_CALLBACK_1(GameOver::GoToMainMenuScene, this));

	auto menu = Menu::create(menuTitle, retryItem, mainMenuItem, NULL);

	menu->alignItemsVerticallyWithPadding(visibleSize.height / 4);
	this->addChild(menu);
	///////////////////////

    return true;
}

void GameOver::GoToGameScene(cocos2d::Ref *pSender)
{
    auto scene = GameScreen::createScene();
    
    Director::getInstance()->replaceScene(scene);
}

void GameOver::GoToMainMenuScene(cocos2d::Ref *pSender)
{
    auto scene = MainMenu::createScene();
    
    Director::getInstance()->replaceScene(scene);
}