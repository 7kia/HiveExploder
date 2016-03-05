#include "PauseScene.h"
#include "GameScene/GameScene.h"
#include "MainMenuScene/MainMenuScene.h"

USING_NS_CC;

Scene* PauseMenu::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = PauseMenu::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool PauseMenu::init()
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
	auto resumeItem = MenuItemImage::create(Buttons::RESUME_BUTTON,
											Buttons::RESUME_BUTTON_CLICK,
											CC_CALLBACK_1(PauseMenu::Resume, this));

	auto retryItem = MenuItemImage::create(Buttons::RETRY_BUTTON,
											Buttons::RETRY_BUTTON_CLICK,
											CC_CALLBACK_1(PauseMenu::Retry, this));

	auto mainMenuItem = MenuItemImage::create(Buttons::MENU_BUTTON,
											Buttons::MENU_BUTTON_CLICK,
											CC_CALLBACK_1(PauseMenu::GoToMainMenuScene, this));

	auto menu = Menu::create(resumeItem, retryItem, mainMenuItem, NULL);
	menu->alignItemsVerticallyWithPadding(visibleSize.height / 8);
	this->addChild(menu);
	/////
	auto backgroundSprite = Sprite::create(PauseSceneTexture::BACKGROUND);
	backgroundSprite->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + origin.y));
	this->addChild(backgroundSprite, -1);

	/////////////////

    return true;
}

void PauseMenu::Resume(cocos2d::Ref *pSender)
{
    Director::getInstance()->popScene();
}

void PauseMenu::GoToMainMenuScene(cocos2d::Ref *pSender)
{
    auto scene = MainMenu::createScene();
    
    Director::getInstance()->popScene();
	Director::getInstance()->replaceScene(TransitionFade::create(1.0, scene));
}

void PauseMenu::Retry(cocos2d::Ref *pSender)
{
    auto scene = GameScreen::createScene();
    
    Director::getInstance()->popScene();
	Director::getInstance()->replaceScene(TransitionFade::create(1.0, scene));
}