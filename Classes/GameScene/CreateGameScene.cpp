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
	typesShoots[TypeShoot::PlayerShoot].SetRect(GameSceneTexture::MARINE_SHOOT_RECT);
	typesShoots[TypeShoot::PlayerShoot].SetVelocity(150.f);
	typesShoots[TypeShoot::PlayerShoot].SetDamage(5);


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
	manageCirlce.SetSprite(Sprite::create(GameSceneTexture::MANAGE_CIRCLE));

	UpdateManageCircle();

	this->addChild(manageCirlce.GetSprite(), 1);
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

	//CLifeObject player;
	auto player = CLifeObject::create();
	player->SetType(typesLifeObjects[TypeLifeObject::Player]);
	player->setPosition(visibleSize.width / 2 + origin.x,
								visibleSize.height / 2 + origin.y);

	lifeObjects.push_back(player);
	this->addChild(player, -1);
}

void GameScreen::CreateEnemys()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();


	auto enemy = CLifeObject::create();
	enemy->SetType(typesLifeObjects[TypeLifeObject::Zergling]);
	enemy->setPosition(visibleSize.width / 2 + origin.x,
								visibleSize.height / 2 + origin.y + visibleSize.height / 4);

	lifeObjects.push_back(enemy);
	this->addChild(enemy, -1);

}

void GameScreen::CreateContactListener()
{
	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(GameScreen::onContactBegin, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);
}




void CLifeObject::CreateShoot(GameScreen * scene, Vec2 directionShoot, vector<CShoot*> &shoots)

{


	auto shoot = CShoot::create();


	shoot->SetType(scene->typesShoots[TypeShoot::PlayerShoot]);
	shoot->SetStartPlace(scene->lifeObjects[0]->getPosition(), scene->manageCirlce.GetDirection(),
							scene->lifeObjects[0]->getContentSize());
	shoot->SetRotation(direction);


	shoots.push_back(shoot);
	scene->addChild(shoot);


	

}//*/