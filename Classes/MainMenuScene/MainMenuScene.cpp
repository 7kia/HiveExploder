//#include "MainMenuScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "MainMenuScene.h"
#include "GameScene/GameScene.h"

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
    
	cocos2d::Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();


	// TODO : desing
	auto menuTitle = MenuItemImage::create(MainMenuTexture::GAME_TITLE,
											MainMenuTexture::GAME_TITLE);
	auto playItem = MenuItemImage::create(Buttons::PLAY_BUTTON,
										Buttons::PLAY_BUTTON_CLICK,
										CC_CALLBACK_1(MainMenu::GoToGameScene, this));
	playItem->setPosition(Vec2(origin.x + visibleSize.width - playItem->getContentSize().width / 2,
								origin.y + playItem->getContentSize().height / 2));

	auto exitItem = MenuItemImage::create(Buttons::EXIT_BUTTON,
		Buttons::EXIT_BUTTON_CLICK,
		CC_CALLBACK_1(MainMenu::GoToExit, this));
	exitItem->setPosition(Vec2(origin.x + visibleSize.width - exitItem->getContentSize().width / 2,
								origin.y + exitItem->getContentSize().height / 2));

	auto menu = Menu::create(menuTitle, playItem, exitItem, NULL);

	menu->alignItemsVerticallyWithPadding(visibleSize.height / 8);
	this->addChild(menu, 1);

	/////
	auto backgroundSprite = Sprite::create(MainMenuTexture::BACKGROUND);
	backgroundSprite->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + origin.y));
	this->addChild(backgroundSprite, -1);

	//////////////////

    return true;
}


void MainMenu::GoToGameScene(cocos2d::Ref *pSender)
{
	auto scene = GameScreen::createScene();

	Director::getInstance()->replaceScene(TransitionFade::create(1.0, scene));
}

void MainMenu::GoToExit(cocos2d::Ref *pSender)
{
	//auto scene = GameScreen::createScene();

	//Director::getInstance()->replaceScene(TransitionFade::create(1.0, scene));
	exit(0);
}