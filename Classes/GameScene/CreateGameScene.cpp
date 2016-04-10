#include "GameScene.h"

using namespace cocos2d;
using namespace std;

void GameScreen::CreateCashes()
{
	// TODO : delete if not need
}



void GameScreen::CreateTypesLifeObjects()
{
	Texture2D* textureMarine = Director::getInstance()->getTextureCache()->addImage(GameSceneRecourses::MARINE);

	m_typesLifeObjects[TypeLifeObject::Player].SetId(TypeLifeObject::ID::Player);
	m_typesLifeObjects[TypeLifeObject::Player].SetTexture(textureMarine);
	m_typesLifeObjects[TypeLifeObject::Player].SetTextureRect(GameSceneRecourses::MARINE_RECT);
	m_typesLifeObjects[TypeLifeObject::Player].SetVelocity(250.f);
	m_typesLifeObjects[TypeLifeObject::Player].SetHealth(40);

	m_typesLifeObjects[TypeLifeObject::Player].SetWeapon(m_typesWeapons[CTypeWeapon::PlayerWeapon]);


	//////////////////////////////////////////////////////////////////////////////////////////////////////////
	Texture2D* textureZergling = Director::getInstance()->getTextureCache()->addImage(GameSceneRecourses::ZERGLING);
	m_typesLifeObjects[TypeLifeObject::Zergling].SetId(TypeLifeObject::ID::Zergling);
	m_typesLifeObjects[TypeLifeObject::Zergling].SetTexture(textureZergling);
	m_typesLifeObjects[TypeLifeObject::Zergling].SetTextureRect(GameSceneRecourses::ZERGLING_RECT);
	m_typesLifeObjects[TypeLifeObject::Zergling].SetVelocity(80.f);
	m_typesLifeObjects[TypeLifeObject::Zergling].SetHealth(35);
	m_typesLifeObjects[TypeLifeObject::Zergling].SetWeapon(m_typesWeapons[CTypeWeapon::ZerglingWeapon]);

	//////////////////////////////////////////////////////////////////////////////////////////////////////////
	Texture2D* textureHydralisk = Director::getInstance()->getTextureCache()->addImage(GameSceneRecourses::HYDRALISK);
	m_typesLifeObjects[TypeLifeObject::Hydralisk].SetId(TypeLifeObject::ID::Hydralisk);
	m_typesLifeObjects[TypeLifeObject::Hydralisk].SetTexture(textureHydralisk);
	m_typesLifeObjects[TypeLifeObject::Hydralisk].SetTextureRect(GameSceneRecourses::HYDRALISK_RECT);
	m_typesLifeObjects[TypeLifeObject::Hydralisk].SetVelocity(80.f);
	m_typesLifeObjects[TypeLifeObject::Hydralisk].SetHealth(180);
	m_typesLifeObjects[TypeLifeObject::Hydralisk].SetWeapon(m_typesWeapons[CTypeWeapon::HydraliskWeapon]);

}

void GameScreen::CreateTypesShoots()
{
	//////////////////////////////////////////////////////////////////////////////////////////////////////////
	Texture2D* textureMarineShoot = Director::getInstance()->getTextureCache()->addImage(GameSceneRecourses::MARINE_SHOOT);
	m_typesShoots[CShootType::PlayerShoot].SetTexture(textureMarineShoot);
	m_typesShoots[CShootType::PlayerShoot].SetRect(GameSceneRecourses::MARINE_SHOOT_RECT);
	//////////////////////////////////////////////////////////////////////////////////////////////////////////
	Texture2D* textureMeleeShoot = Director::getInstance()->getTextureCache()->addImage(GameSceneRecourses::MELEE_SHOOT);
	m_typesShoots[CShootType::MeleeShoot].SetTexture(textureMeleeShoot);
	m_typesShoots[CShootType::MeleeShoot].SetRect(GameSceneRecourses::MELEE_SHOOT_RECT);
	//////////////////////////////////////////////////////////////////////////////////////////////////////////
}

void GameScreen::CreateTypesWeapons()
{
	m_typesWeapons[CTypeWeapon::PlayerWeapon].SetId(CTypeWeapon::PlayerWeapon);
	m_typesWeapons[CTypeWeapon::PlayerWeapon].SetDamage(3);
	m_typesWeapons[CTypeWeapon::PlayerWeapon].SetTime(1.f);
	m_typesWeapons[CTypeWeapon::PlayerWeapon].SetTypeShoot(m_typesShoots[CShootType::PlayerShoot]);
	m_typesWeapons[CTypeWeapon::PlayerWeapon].SetVelocity(750.f);

	m_typesWeapons[CTypeWeapon::ZerglingWeapon].SetId(CTypeWeapon::ZerglingWeapon);
	m_typesWeapons[CTypeWeapon::ZerglingWeapon].SetDamage(5);
	m_typesWeapons[CTypeWeapon::ZerglingWeapon].SetTime(1.f);
	m_typesWeapons[CTypeWeapon::ZerglingWeapon].SetTypeShoot(m_typesShoots[CShootType::MeleeShoot]);
	m_typesWeapons[CTypeWeapon::ZerglingWeapon].SetVelocity(750.f);

	m_typesWeapons[CTypeWeapon::HydraliskWeapon].SetId(CTypeWeapon::HydraliskWeapon);
	m_typesWeapons[CTypeWeapon::HydraliskWeapon].SetDamage(13);
	m_typesWeapons[CTypeWeapon::HydraliskWeapon].SetTime(1.f);
	m_typesWeapons[CTypeWeapon::HydraliskWeapon].SetTypeShoot(m_typesShoots[CShootType::PlayerShoot]);// TODO : replace
	m_typesWeapons[CTypeWeapon::HydraliskWeapon].SetVelocity(750.f);
}

void GameScreen::CreateMenu()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	MenuItemImage* pauseButton = MenuItemImage::create(Buttons::PAUSE_BUTTON,
											Buttons::PAUSE_BUTTON_CLICK,
											CC_CALLBACK_1(GameScreen::GoToPauseScene, this));

	pauseButton->setPositionX(pauseButton->getContentSize().width / 2 + origin.x);
	pauseButton->setPositionY(pauseButton->getContentSize().height + origin.y);

	Menu* menu = Menu::create(pauseButton, NULL);
	menu->setPosition(Point::ZERO);

	menu->setName("menu");
	this->addChild(menu, GameSceneRecourses::levelInterface);
}

void GameScreen::CreateMoveCircle()
{
	m_manageCirlce.SetSprite(Sprite::create(GameSceneRecourses::MANAGE_CIRCLE));

	UpdateManageCircle();

	this->addChild(m_manageCirlce.GetSprite(), GameSceneRecourses::levelInterface);
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

void GameScreen::CreateCamera()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	Vec3 spritePos = Vec3(visibleSize.width / 2 + origin.x,
		visibleSize.height / 2 + origin.y,
		1);

	setCameraMask((unsigned short)CameraFlag::DEFAULT, true);

	// TOOD : CAMERA
	m_camera = Camera::Camera::createPerspective(60, (float)visibleSize.width / visibleSize.height, 1.0, 1000);
	m_camera->setCameraFlag(CameraFlag::DEFAULT);
	//the calling order matters, we should first call setPosition3D, then call lookAt.
	m_camera->setPosition3D(spritePos + Vec3(0, 0, 800));
	m_camera->lookAt(spritePos, Vec3(0.0, 1.0, 0.0));

	this->addChild(m_camera);
}

void GameScreen::CreateMap()
{
	m_tileMap = CCTMXTiledMap::create(GameSceneRecourses::MAP);

	this->addChild(m_tileMap, GameSceneRecourses::levelMap);
}

void GameScreen::CreateLifeObjects()
{
	ValueVector objects = m_tileMap->getObjectGroup("LifeObjects")->getObjects();

	ValueMap value;
	for (const auto& object : objects)
	{
		value = object.asValueMap();
		
		CLifeObject* lifeObjects = new CLifeObject();
		lifeObjects->SetType(m_typesLifeObjects[GetIdTypeLifeObject(value["name"].asString())]);

		lifeObjects->setPosition(value["x"].asFloat(),
								value["y"].asFloat());

		m_lifeObjects.push_back(lifeObjects);
		addChild(lifeObjects, GameSceneRecourses::levelObjects);
	}

}

void GameScreen::CreateContactListener()
{
	EventListenerPhysicsContact* contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(GameScreen::onContactBegin, this);
	contactListener->onContactPreSolve = CC_CALLBACK_1(GameScreen::onContactPreSolve, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);
}

void CLifeObject::CreateShoot(GameScreen * scene, Vec2 directionShoot, vector<CShoot*> &shoots)
{
	CShoot* shoot = new CShoot();

	shoot->SetType(scene->m_typesShoots[CShootType::PlayerShoot]);
	shoot->SetStartPlace(scene->m_lifeObjects[0]->getPosition(), scene->m_manageCirlce.GetDirection(),
							scene->m_lifeObjects[0]->getContentSize());
	shoot->SetDirection(directionShoot);

	shoots.push_back(shoot);
	scene->addChild(shoot, GameSceneRecourses::levelObjects);

}

TypeLifeObject::ID GameScreen::GetIdTypeLifeObject(const std::string & name)
{
	if (name == "Player")
	{
		return TypeLifeObject::Player;
	}
	else if (name == "Zergling")
	{
		return TypeLifeObject::Zergling;
	}
	else if (name == "Hydralisk")
	{
		return TypeLifeObject::Hydralisk;
	}
}