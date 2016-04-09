#include "VictoryScene.h"
#include "GameScene/GameScene.h"
#include "MainMenuScene/MainMenuScene.h"

USING_NS_CC;

Scene* Victory::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Victory::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Victory::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
	CreateMenu();
	CreateBackground();


    return true;
}

void Victory::CreateMenu()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	auto mainMenuItem = MenuItemImage::create(Buttons::MENU_BUTTON,
		Buttons::MENU_BUTTON_CLICK,
		CC_CALLBACK_1(Victory::GoToMainMenuScene, this));

	auto menu = Menu::create(mainMenuItem, NULL);

	menu->alignItemsVerticallyWithPadding(visibleSize.height / 8);


	this->addChild(menu);

}

void Victory::CreateBackground()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	auto backgroundSprite = Sprite::create(VictoryTexture::BACKGROUND);
	backgroundSprite->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + origin.y));
	this->addChild(backgroundSprite, -1);
}


void Victory::GoToMainMenuScene(cocos2d::Ref *pSender)
{
    auto scene = MainMenu::createScene();
    
	Director::getInstance()->replaceScene(TransitionFade::create(1.0, scene));
}