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
    if ( !Layer::init() )
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

void GameScreen::SetPhysicsWorld(cocos2d::PhysicsWorld * world)
{
	m_World = world;
	m_World->setGravity(cocos2d::Vect(0, 0));	
}

bool GameScreen::onContactBegin(PhysicsContact& contact)
{
	//GoToGameOverScene(this);
	auto bodyA = contact.getShapeA()->getBody();
	auto bodyB = contact.getShapeB()->getBody();
	CCollision* collisionA = static_cast<CCollision*>(bodyA);
	CCollision* collisionB = static_cast<CCollision*>(bodyB);

	auto entityA = collisionA->GetMaster();
	auto entityB = collisionB->GetMaster();

	CEntity::idClass idA = entityA->GetIdClass();
	CEntity::idClass idB = entityB->GetIdClass();

	if ((idA == CEntity::idClass::LifeObject) && (idB == CEntity::idClass::Shoot))
	{
		dynamic_cast<CLifeObject*>(entityA)->AddHealth(-dynamic_cast<CShoot*>(entityB)->GetDamage());
		dynamic_cast<CShoot*>(entityB)->SetVelocity(0.f);

	}
	else if ((idB == CEntity::idClass::LifeObject) && (idA == CEntity::idClass::Shoot))
	{
		dynamic_cast<CLifeObject*>(entityB)->AddHealth(-dynamic_cast<CShoot*>(entityA)->GetDamage());
		dynamic_cast<CShoot*>(entityA)->SetVelocity(0.f);

	}

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