//#include "MainMenuScene.h"
#include "../Classes/Config.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "MainMenuScene.h"
#include "GameScene.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* MainMenu::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MainMenu::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainMenu::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();


	// TODO : desing
	auto menuTitle = MenuItemImage::create(MainMenuTexture::GAME_TITLE,
											MainMenuTexture::GAME_TITLE);
	auto playItem = MenuItemImage::create(Buttons::PLAY_BUTTON,
										Buttons::PLAY_BUTTON_CLICK,
										CC_CALLBACK_1(MainMenu::GoToGameScene, this));

	auto menu = Menu::create(menuTitle, playItem, NULL);
	menu->alignItemsVerticallyWithPadding(visibleSize.height / 4);
	this->addChild(menu);
	//////////////////

    return true;
}


void MainMenu::GoToGameScene(cocos2d::Ref *pSender)
{
	auto scene = GameScreen::createScene();

	Director::getInstance()->replaceScene(scene);
}