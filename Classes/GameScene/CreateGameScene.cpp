#include "GameScene.h"

using namespace cocos2d;
using namespace std;

void GameScreen::CreateCashes()
{

}

void GameScreen::CreateTypesLifeObjects()
{
	auto textureMarine = Director::getInstance()->getTextureCache()->addImage(GameSceneTexture::PATH_TEXTURE
																			+ GameSceneTexture::MARINE);
	typesLifeObjects[TypeLifeObject::Player].SetTexture(textureMarine);
	typesLifeObjects[TypeLifeObject::Player].SetTextureRect(GameSceneTexture::MARINE_RECT);
	typesLifeObjects[TypeLifeObject::Player].SetVelocity(150.f);

	typesLifeObjects[TypeLifeObject::Player].SetHealth(40);

	//////////////////////////////////////////////////////////////////////////////////////////////////////////
	auto textureZergling = Director::getInstance()->getTextureCache()->addImage(GameSceneTexture::PATH_TEXTURE
																			+ GameSceneTexture::ZERGLING);
	typesLifeObjects[TypeLifeObject::Zergling].SetTexture(textureZergling);
	typesLifeObjects[TypeLifeObject::Zergling].SetTextureRect(GameSceneTexture::ZERGLING_RECT);
	typesLifeObjects[TypeLifeObject::Zergling].SetVelocity(150.f);

	typesLifeObjects[TypeLifeObject::Zergling].SetHealth(35);
	//////////////////////////////////////////////////////////////////////////////////////////////////////////
}

void GameScreen::CreateTypesShoots()
{
	//////////////////////////////////////////////////////////////////////////////////////////////////////////

	auto textureMarineShoot = Director::getInstance()->getTextureCache()->addImage(GameSceneTexture::PATH_TEXTURE
																					+ GameSceneTexture::MARINE_SHOOT);

	typesShoots[TypeShoot::PlayerShoot].SetTexture(textureMarineShoot);
	typesShoots[TypeShoot::PlayerShoot].SetRect(GameSceneTexture::ZERGLING_RECT);
	typesShoots[TypeShoot::PlayerShoot].SetVelocity(150.f);

	//////////////////////////////////////////////////////////////////////////////////////////////////////////

}

void GameScreen::CreateMenu()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	auto pauseButton = MenuItemImage::create(Buttons::PAUSE_BUTTON,
											Buttons::PAUSE_BUTTON_CLICK,
											CC_CALLBACK_1(GameScreen::GoToPauseScene, this));

	pauseButton->setPositionX(pauseButton->getContentSize().width / 2 + origin.x);
	pauseButton->setPositionY(visibleSize.height - pauseButton->getContentSize().height + origin.y);

	auto menu = Menu::create(pauseButton, NULL);
	menu->setPosition(Point::ZERO);

	this->addChild(menu);
}

void GameScreen::CreateMoveCircle()
{
	manageCirlce.SetSprite(std::make_shared<cocos2d::Sprite>(Sprite::create(GameSceneTexture::MANAGE_CIRCLE)));

	UpdateManageCircle();

	this->addChild(manageCirlce.GetSprite().get(), 1);
}

void GameScreen::CreateListener()
{
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);

	listener->onTouchBegan = CC_CALLBACK_2(GameScreen::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(GameScreen::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(GameScreen::onTouchEnded, this);
	listener->onTouchCancelled = CC_CALLBACK_2(GameScreen::onTouchCancelled, this);

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}

void GameScreen::CreatePlayer()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	CLifeObject player;
	//auto sprite = ;
	player.SetSprite(std::make_shared<cocos2d::Sprite>(Sprite::create()));
	player.SetType(typesLifeObjects[TypeLifeObject::Player]);
	player.SetPosition(visibleSize.width / 2 + origin.x,
								visibleSize.height / 2 + origin.y);

	lifeObjects.push_back(player);
	this->addChild(player.GetSprite().get(), -1);
}

void GameScreen::CreateEnemys()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	CLifeObject enemy;
	//auto sprite = Sprite::create();
	enemy.SetSprite(std::make_shared<cocos2d::Sprite>(Sprite::create()));
	enemy.SetType(typesLifeObjects[TypeLifeObject::Zergling]);
	enemy.SetPosition(visibleSize.width / 2 + origin.x,
								visibleSize.height / 2 + origin.y + visibleSize.height / 4);

	lifeObjects.push_back(enemy);
	this->addChild(enemy.GetSprite().get(), -1);
}

void GameScreen::CreateContactListener()
{
	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(GameScreen::onContactBegin, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);
}



	///*
void CLifeObject::CreateShoot(GameScreen * scene, vector<CShoot> &shoots)
{

	CShoot addShoot;
	//auto sprite = Sprite::create();
	addShoot.SetSprite(std::make_shared<cocos2d::Sprite>(Sprite::create()));


	addShoot.SetType(scene->typesShoots[TypeShoot::PlayerShoot]);
	addShoot.SetStartPlace(scene->lifeObjects[0].GetPosition(), scene->manageCirlce.GetDirection(),
							scene->lifeObjects[0].GetSprite()->getContentSize());

	shoots.push_back(addShoot);
	scene->addChild(addShoot.GetSprite().get());

	

}//*/