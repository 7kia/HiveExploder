#include "GameScene.h"
#include "PauseScene/PauseScene.h"
#include "GameOverScene/GameOverScene.h"
#include "VictoryScene/VictoryScene.h"

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
    if ( !Layer::init() )
    {
        return false;
    }

	CreateCashes();
	CreateTypesShoots();
	CreateTypesWeapons();
	CreateTypesLifeObjects();
	CreateFunctionsForBonuses();
	CreateTypesBonuses();

	CreateCamera();
	CreateMap();
	CreateLifeObjects();
	CreateBonuses();
	CreateWalls();

	CreateMenu();
	CreateMoveCircle();


	CreateContactListener();

	this->scheduleUpdate();

	// this->schedule(schedule_selector(GameScreen::spawnAsteroid), 1.0);
	//this->schedule(CC_SCHEDULE_SELECTOR(PhysicsDemoCollisionProcessing::tick), 0.3f);

	CreateListener();
	////////////////////////

    return true;
}

void GameScreen::SetPhysicsWorld(cocos2d::PhysicsWorld * world)
{
	m_World = world;
	m_World->setGravity(cocos2d::Vect(0, 0));	
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