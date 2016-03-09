#include "GameScene.h"
#include "PauseScene/PauseScene.h"
#include "GameOverScene/GameOverScene.h"
#include "VictoryrScene/VictoryScene.h"

USING_NS_CC;

Scene* GameScreen::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::createWithPhysics();

	// 'layer' is an autorelease object
	auto layer = GameScreen::create();
	layer->SetPhysicsWorld(scene->getPhysicsWorld());

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
	if (!Layer::init())
	{
		return false;
	}

	//Size visibleSize = Director::getInstance()->getVisibleSize();
	//Point origin = Director::getInstance()->getVisibleOrigin();
	CreateCashes();
	CreateTypesLifeObjects();
	CreateTypesShoots();

	CreateMenu();
	CreateMoveCircle();

	CreatePlayer();
	CreateEnemys();

	CreateContactListener();

	this->scheduleUpdate();

	// this->schedule(schedule_selector(GameScreen::spawnAsteroid), 1.0);
	//this->schedule(CC_SCHEDULE_SELECTOR(PhysicsDemoCollisionProcessing::tick), 0.3f);

	CreateListener();
	////////////////////////

	return true;
}

bool GameScreen::onContactBegin(PhysicsContact& contact)
{
	//GoToGameOverScene(this);


	return true;
}

bool GameScreen::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event * event)
{
	isTouching = true;
	touchPosition = touch->getLocation();

	return true;
}

void GameScreen::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event * event)
{
	touchPosition = touch->getLocation();
}

void GameScreen::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event * event)
{
	isTouching = false;
}

void GameScreen::onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event * event)
{
	onTouchEnded(touch, event);
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


void GameScreen::GoToVictoryScene(cocos2d::Ref *pSender)
{
	auto scene = Victory::createScene();

	Director::getInstance()->pushScene(TransitionFade::create(1.0, scene));
}