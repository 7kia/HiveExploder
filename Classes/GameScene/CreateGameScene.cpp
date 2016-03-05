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
	m_typesLifeObjects[TypeLifeObject::Player].SetTexture(textureMarine);
	m_typesLifeObjects[TypeLifeObject::Player].SetTextureRect(GameSceneTexture::MARINE_RECT);
	m_typesLifeObjects[TypeLifeObject::Player].SetVelocity(150.f);

	m_typesLifeObjects[TypeLifeObject::Player].SetHealth(40);

	//////////////////////////////////////////////////////////////////////////////////////////////////////////
	auto textureZergling = Director::getInstance()->getTextureCache()->addImage(GameSceneTexture::PATH_TEXTURE
																			+ GameSceneTexture::ZERGLING);
	m_typesLifeObjects[TypeLifeObject::Zergling].SetTexture(textureZergling);
	m_typesLifeObjects[TypeLifeObject::Zergling].SetTextureRect(GameSceneTexture::ZERGLING_RECT);
	m_typesLifeObjects[TypeLifeObject::Zergling].SetVelocity(150.f);

	m_typesLifeObjects[TypeLifeObject::Zergling].SetHealth(35);
	//////////////////////////////////////////////////////////////////////////////////////////////////////////
}

void GameScreen::CreateTypesShoots()
{
	//////////////////////////////////////////////////////////////////////////////////////////////////////////

	auto textureMarineShoot = Director::getInstance()->getTextureCache()->addImage(GameSceneTexture::PATH_TEXTURE
																					+ GameSceneTexture::MARINE_SHOOT);
	m_typesShoots[ShootType::PlayerShoot].SetTexture(textureMarineShoot);
	m_typesShoots[ShootType::PlayerShoot].SetRect(GameSceneTexture::MARINE_SHOOT_RECT);
	m_typesShoots[ShootType::PlayerShoot].SetVelocity(150.f);
	m_typesShoots[ShootType::PlayerShoot].SetDamage(5);
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
	m_manageCirlce.SetSprite(Sprite::create(GameSceneTexture::MANAGE_CIRCLE));

	UpdateManageCircle();

	this->addChild(m_manageCirlce.GetSprite(), 1);
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
	CLifeObject* player = new CLifeObject();
	player->SetType(m_typesLifeObjects[TypeLifeObject::Player]);
	player->setPosition(visibleSize.width / 2 + origin.x,
								visibleSize.height / 2 + origin.y);

	m_lifeObjects.push_back(player);
	addChild(player, -1);
}

void GameScreen::CreateEnemys()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	CLifeObject* enemy = new CLifeObject();
	enemy->SetType(m_typesLifeObjects[TypeLifeObject::Zergling]);
	enemy->setPosition(visibleSize.width / 2 + origin.x,
								visibleSize.height / 2 + origin.y + visibleSize.height / 4);

	m_lifeObjects.push_back(enemy);
	addChild(enemy, -1);
}

void GameScreen::CreateContactListener()
{
	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(GameScreen::onContactBegin, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);
}



	///*
void CLifeObject::CreateShoot(GameScreen * scene, Vec2 directionShoot, vector<CShoot*> &shoots)
{
	direction = directionShoot;

	CShoot* shoot = new CShoot();

	shoot->SetType(scene->m_typesShoots[ShootType::PlayerShoot]);
	shoot->SetStartPlace(scene->m_lifeObjects[0]->getPosition(), scene->m_manageCirlce.GetDirection(),
							scene->m_lifeObjects[0]->getContentSize());
	shoot->SetDirection(direction);

	shoots.push_back(shoot);
	scene->addChild(shoot, -1);

}//*/