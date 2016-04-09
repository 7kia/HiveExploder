#include "GameScene.h"

using namespace cocos2d;
using namespace std;

void GameScreen::CreateCashes()
{

}



void GameScreen::CreateTypesLifeObjects()
{
	Texture2D* textureMarine = Director::getInstance()->getTextureCache()->addImage(GameSceneRecourses::PATH
																			+ GameSceneRecourses::MARINE);

	m_typesLifeObjects[TypeLifeObject::Player].SetId(TypeLifeObject::ID::Player);
	m_typesLifeObjects[TypeLifeObject::Player].SetTexture(textureMarine);
	m_typesLifeObjects[TypeLifeObject::Player].SetTextureRect(GameSceneRecourses::MARINE_RECT);
	m_typesLifeObjects[TypeLifeObject::Player].SetVelocity(250.f);

	m_typesLifeObjects[TypeLifeObject::Player].SetHealth(40);
	m_typesLifeObjects[TypeLifeObject::Player].SetDamage(5);


	//////////////////////////////////////////////////////////////////////////////////////////////////////////
	Texture2D* textureZergling = Director::getInstance()->getTextureCache()->addImage(GameSceneRecourses::PATH
																			+ GameSceneRecourses::ZERGLING);
	m_typesLifeObjects[TypeLifeObject::Zergling].SetId(TypeLifeObject::ID::Zergling);
	m_typesLifeObjects[TypeLifeObject::Zergling].SetTexture(textureZergling);
	m_typesLifeObjects[TypeLifeObject::Zergling].SetTextureRect(GameSceneRecourses::ZERGLING_RECT);
	m_typesLifeObjects[TypeLifeObject::Zergling].SetVelocity(80.f);

	m_typesLifeObjects[TypeLifeObject::Zergling].SetHealth(35);
	m_typesLifeObjects[TypeLifeObject::Zergling].SetDamage(5);
	//////////////////////////////////////////////////////////////////////////////////////////////////////////
}

void GameScreen::CreateTypesShoots()
{
	//////////////////////////////////////////////////////////////////////////////////////////////////////////
	Texture2D* textureMarineShoot = Director::getInstance()->getTextureCache()->addImage(GameSceneRecourses::PATH
																					+ GameSceneRecourses::MARINE_SHOOT);
	m_typesShoots[ShootType::PlayerShoot].SetTexture(textureMarineShoot);
	m_typesShoots[ShootType::PlayerShoot].SetRect(GameSceneRecourses::MARINE_SHOOT_RECT);
	m_typesShoots[ShootType::PlayerShoot].SetVelocity(750.f);
	m_typesShoots[ShootType::PlayerShoot].SetDamage(5);
	//////////////////////////////////////////////////////////////////////////////////////////////////////////
}

void GameScreen::CreateMenu()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	MenuItemImage* pauseButton = MenuItemImage::create(Buttons::PAUSE_BUTTON,
											Buttons::PAUSE_BUTTON_CLICK,
											CC_CALLBACK_1(GameScreen::GoToPauseScene, this));

	pauseButton->setPositionX(pauseButton->getContentSize().width / 2 + origin.x);
	//visibleSize.height - // TODO : replace Y position
	pauseButton->setPositionY( pauseButton->getContentSize().height + origin.y);

	Menu* menu = Menu::create(pauseButton, NULL);
	menu->setPosition(Point::ZERO);

	this->addChild(menu);
}

void GameScreen::CreateMoveCircle()
{
	m_manageCirlce.SetSprite(Sprite::create(GameSceneRecourses::MANAGE_CIRCLE));

	UpdateManageCircle();

	this->addChild(m_manageCirlce.GetSprite(), 1);
}

void GameScreen::CreateListener()
{
	EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);

	listener->onTouchBegan = CC_CALLBACK_2(GameScreen::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(GameScreen::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(GameScreen::onTouchEnded, this);
	listener->onTouchCancelled = CC_CALLBACK_2(GameScreen::onTouchCancelled, this);

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}

void GameScreen::CreateMap()
{
	m_tileMap = CCTMXTiledMap::create(GameSceneRecourses::MAP);


	this->addChild(m_tileMap, -2);
}

void GameScreen::CreatePlayer()
{
	ValueMap objects = m_tileMap->getObjectGroup("LifeObjects")->getObject("Player");

	objects["x"].asFloat();
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	//CLifeObject player;
	CLifeObject* player = new CLifeObject();
	player->SetType(m_typesLifeObjects[TypeLifeObject::Player]);
	//player->setPosition(visibleSize.width / 2 + origin.x,
	//							visibleSize.height / 2 + origin.y);
	player->setPosition(objects["x"].asFloat(),
						objects["y"].asFloat());

	m_lifeObjects.push_back(player);
	addChild(player, -1);
}

void GameScreen::CreateEnemys()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	for (size_t index = 0; index < m_amountMonsters; index++)
	{
		CLifeObject* enemy = new CLifeObject();
		enemy->SetType(m_typesLifeObjects[TypeLifeObject::Zergling]);

		float randomShiftX = CCRANDOM_0_1() *  visibleSize.width / 2;
		enemy->setPositionX(visibleSize.width / 2  + origin.x
							+ randomShiftX);

		enemy->setPositionY(visibleSize.height  + origin.y );

		m_lifeObjects.push_back(enemy);
		addChild(enemy, -1);
	}

}

void GameScreen::CreateContactListener()
{
	EventListenerPhysicsContact* contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(GameScreen::onContactBegin, this);
	contactListener->onContactPreSolve = CC_CALLBACK_1(GameScreen::onContactPreSolve, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);
}



	///*
void CLifeObject::CreateShoot(GameScreen * scene, Vec2 directionShoot, vector<CShoot*> &shoots)
{
	CShoot* shoot = new CShoot();

	shoot->SetType(scene->m_typesShoots[ShootType::PlayerShoot]);
	shoot->SetStartPlace(scene->m_lifeObjects[0]->getPosition(), scene->m_manageCirlce.GetDirection(),
							scene->m_lifeObjects[0]->getContentSize());
	shoot->SetDirection(directionShoot);

	shoots.push_back(shoot);
	scene->addChild(shoot, -1);

}//*/