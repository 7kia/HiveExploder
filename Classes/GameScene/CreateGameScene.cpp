#include "GameScene.h"

using namespace cocos2d;
using namespace std;

cocos2d::Vec2 GameScreen::GetMiddleWindow() const
{
	Size size = Director::getInstance()->getVisibleSize();
	Vec2 result = Vec2(size.width, size.height);
	result.x /= 2.f;
	result.y /= 2.f;
	return result;
}

CLifeObject & GameScreen::GetPlayer() const
{
	return *m_lifeObjects[m_id_player];
}

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
	m_typesLifeObjects[TypeLifeObject::Player].SetHealth(400);

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
	m_typesShoots[CShootType::PlayerShoot].SetTextureRect(GameSceneRecourses::MARINE_SHOOT_RECT);
	//////////////////////////////////////////////////////////////////////////////////////////////////////////
	Texture2D* textureHydraliskShoot = Director::getInstance()->getTextureCache()->addImage(GameSceneRecourses::HYDRALISK_SHOOT);
	m_typesShoots[CShootType::HydraliskShoot].SetTexture(textureHydraliskShoot);
	m_typesShoots[CShootType::HydraliskShoot].SetTextureRect(GameSceneRecourses::HYDRALISK_SHOOT_RECT);
	//////////////////////////////////////////////////////////////////////////////////////////////////////////
	Texture2D* textureGrenade = Director::getInstance()->getTextureCache()->addImage(GameSceneRecourses::GRENADE);
	m_typesShoots[CShootType::Grenade].SetTexture(textureGrenade);
	m_typesShoots[CShootType::Grenade].SetTextureRect(GameSceneRecourses::GRENADE_RECT);
	//////////////////////////////////////////////////////////////////////////////////////////////////////////
	Texture2D* texturePlasmaShoot = Director::getInstance()->getTextureCache()->addImage(GameSceneRecourses::PLASMA_SHOOT);
	m_typesShoots[CShootType::Plasma].SetTexture(texturePlasmaShoot);
	m_typesShoots[CShootType::Plasma].SetTextureRect(GameSceneRecourses::PLASMA_SHOOT_RECT);
	//////////////////////////////////////////////////////////////////////////////////////////////////////////
	Texture2D* textureMeleeShoot = Director::getInstance()->getTextureCache()->addImage(GameSceneRecourses::MELEE_SHOOT);
	m_typesShoots[CShootType::MeleeShoot].SetTexture(textureMeleeShoot);
	m_typesShoots[CShootType::MeleeShoot].SetTextureRect(GameSceneRecourses::MELEE_SHOOT_RECT);
	//////////////////////////////////////////////////////////////////////////////////////////////////////////
}

void GameScreen::CreateTypesWeapons()
{
	m_typesWeapons[CTypeWeapon::PlayerWeapon].SetId(CTypeWeapon::PlayerWeapon);
	m_typesWeapons[CTypeWeapon::PlayerWeapon].SetDamage(3);
	m_typesWeapons[CTypeWeapon::PlayerWeapon].SetTime(0.15f);
	m_typesWeapons[CTypeWeapon::PlayerWeapon].SetTypeShoot(m_typesShoots[CShootType::PlayerShoot]);
	m_typesWeapons[CTypeWeapon::PlayerWeapon].SetVelocity(750.f);
	m_typesWeapons[CTypeWeapon::PlayerWeapon].SetDistanse(750.f);

	m_typesWeapons[CTypeWeapon::ZerglingWeapon].SetId(CTypeWeapon::ZerglingWeapon);
	m_typesWeapons[CTypeWeapon::ZerglingWeapon].SetDamage(5);
	m_typesWeapons[CTypeWeapon::ZerglingWeapon].SetTime(1.f);
	m_typesWeapons[CTypeWeapon::ZerglingWeapon].SetTypeShoot(m_typesShoots[CShootType::MeleeShoot]);
	m_typesWeapons[CTypeWeapon::ZerglingWeapon].SetVelocity(750.f);
	m_typesWeapons[CTypeWeapon::ZerglingWeapon].SetDistanse(70.f);

	m_typesWeapons[CTypeWeapon::HydraliskWeapon].SetId(CTypeWeapon::HydraliskWeapon);
	m_typesWeapons[CTypeWeapon::HydraliskWeapon].SetDamage(3);
	m_typesWeapons[CTypeWeapon::HydraliskWeapon].SetTime(1.f);
	m_typesWeapons[CTypeWeapon::HydraliskWeapon].SetTypeShoot(m_typesShoots[CShootType::HydraliskShoot]);// TODO : replace
	m_typesWeapons[CTypeWeapon::HydraliskWeapon].SetVelocity(750.f);
	m_typesWeapons[CTypeWeapon::HydraliskWeapon].SetDistanse(550.f);

	m_typesWeapons[CTypeWeapon::GrenadeGun].SetId(CTypeWeapon::GrenadeGun);
	m_typesWeapons[CTypeWeapon::GrenadeGun].SetDamage(40);
	m_typesWeapons[CTypeWeapon::GrenadeGun].SetTime(1.f);
	m_typesWeapons[CTypeWeapon::GrenadeGun].SetTypeShoot(m_typesShoots[CShootType::Grenade]);// TODO : replace
	m_typesWeapons[CTypeWeapon::GrenadeGun].SetVelocity(750.f);
	m_typesWeapons[CTypeWeapon::GrenadeGun].SetDistanse(550.f);

	m_typesWeapons[CTypeWeapon::PlasmaGun].SetId(CTypeWeapon::PlasmaGun);
	m_typesWeapons[CTypeWeapon::PlasmaGun].SetDamage(50);
	m_typesWeapons[CTypeWeapon::PlasmaGun].SetTime(0.5f);
	m_typesWeapons[CTypeWeapon::PlasmaGun].SetTypeShoot(m_typesShoots[CShootType::Plasma]);// TODO : replace
	m_typesWeapons[CTypeWeapon::PlasmaGun].SetVelocity(750.f);
	m_typesWeapons[CTypeWeapon::PlasmaGun].SetDistanse(550.f);

}

void GameScreen::CreateTypesBonuses()
{
	//////////////////////////////////////////////////////////////////////////////////////////////////////////
	Texture2D* textureMedPack = Director::getInstance()->getTextureCache()->addImage(GameSceneRecourses::BONUS_MED_PACK);

	m_typeBonuses[CBonusesType::MedicineChest].SetTexture(textureMedPack);
	m_typeBonuses[CBonusesType::MedicineChest].SetTextureRect(GameSceneRecourses::BONUS_RECT);
	m_typeBonuses[CBonusesType::MedicineChest].SetAction(m_functions_for_bonuses[CBonusesType::MedicineChest]);

	//////////////////////////////////////////////////////////////////////////////////////////////////////////
	Texture2D* textureGrenadeGun = Director::getInstance()->getTextureCache()->addImage(GameSceneRecourses::BONUS_GRENADE_GUN);

	m_typeBonuses[CBonusesType::GrenadeGun].SetTexture(textureGrenadeGun);
	m_typeBonuses[CBonusesType::GrenadeGun].SetTextureRect(GameSceneRecourses::BONUS_RECT);
	m_typeBonuses[CBonusesType::GrenadeGun].SetAction(m_functions_for_bonuses[CBonusesType::GrenadeGun]);
	//////////////////////////////////////////////////////////////////////////////////////////////////////////
	Texture2D* texturePlasmaGun = Director::getInstance()->getTextureCache()->addImage(GameSceneRecourses::BONUS_PLASMA_GUN);

	m_typeBonuses[CBonusesType::PlasmaGun].SetTexture(texturePlasmaGun);
	m_typeBonuses[CBonusesType::PlasmaGun].SetTextureRect(GameSceneRecourses::BONUS_RECT);
	m_typeBonuses[CBonusesType::PlasmaGun].SetAction(m_functions_for_bonuses[CBonusesType::PlasmaGun]);
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
	pauseButton->setPositionY(pauseButton->getContentSize().height + origin.y);

	Menu* menu = Menu::create(pauseButton, NULL);
	menu->setPosition(Point::ZERO);

	menu->setName("menu");
	this->addChild(menu);
}

void GameScreen::CreateMoveCircle()
{
	m_manageCirlce.SetSprite(Sprite::create(GameSceneRecourses::MANAGE_CIRCLE));

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

// TODO ; redesign
void GameScreen::CreateCamera()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	Vec3 spritePos = Vec3(visibleSize.width / 2 + origin.x,
		visibleSize.height / 2 + origin.y,
		1);

	//setCameraMask((unsigned short)CameraFlag::DEFAULT, true);

	m_camera = Director::getInstance()->getRunningScene()->getDefaultCamera();
	// TOOD : CAMERA
	//m_camera = Camera::Camera::createPerspective(60, (float)visibleSize.width / visibleSize.height, 1.0, 1000);
	//m_camera->setCameraFlag(CameraFlag::DEFAULT);
	//the calling order matters, we should first call setPosition3D, then call lookAt.
	//m_camera->setPosition3D(spritePos + Vec3(0, 0, 800));
	//m_camera->lookAt(spritePos, Vec3(0.0, 1.0, 0.0));

	//this->addChild(m_camera);
}

void GameScreen::CreateMap()
{
	m_tileMap = CCTMXTiledMap::create(GameSceneRecourses::MAP);

	this->addChild(m_tileMap, GameSceneRecourses::levelMap);
}

void GameScreen::CreateWalls()
{
	ValueVector walls = m_tileMap->getObjectGroup("Walls")->getObjects();
	/*

	*/
	ValueMap value;
	for (const auto& wall : walls)
	{
		value = wall.asValueMap();

		Size size = Size(value["width"].asFloat(), value["height"].asFloat());
		PhysicsBody* bodyWall = PhysicsBody::createBox(size,
			PhysicsMaterial(0.1f, 1.0f, 0.0f));
		bodyWall->setDynamic(false);

		CEntity* spriteWall = new CEntity();
		spriteWall->setContentSize(size);
		spriteWall->setPhysicsBody(bodyWall);

		Vec2 pos = Vec2(value["x"].asFloat(), value["y"].asFloat());
		spriteWall->setPosition(pos);
		spriteWall->setTextureRect(m_typesShoots[CShootType::MeleeShoot].GetTextureRectangle());
		spriteWall->setTexture(m_typesShoots[CShootType::MeleeShoot].GetTexture());



		addChild(spriteWall, GameSceneRecourses::levelObjects);
	}


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

void GameScreen::CreateBonuses()
{
	ValueVector objects = m_tileMap->getObjectGroup("Bonuses")->getObjects();

	ValueMap value;
	for (const auto& object : objects)
	{
		value = object.asValueMap();

		CBonus* bonus = new CBonus();
		bonus->SetType(m_typeBonuses[GetIdTypeBonuses(value["name"].asString())]);

		bonus->setPosition(value["x"].asFloat(),
			value["y"].asFloat());

		m_bonuses.push_back(bonus);
		addChild(bonus, GameSceneRecourses::levelObjects);
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

	shoot->SetWeapon(GetWeapon());
	shoot->SetType(GetWeapon().GetTypeShoot());
	shoot->SetStartPlace(getPosition(), this->GetDirection(),
							getContentSize());
	shoot->SetDirection(directionShoot);

	shoots.push_back(shoot);
	scene->addChild(shoot, GameSceneRecourses::levelObjects);

	SetWeaponState(CWeapon::IdState::NotActive);
	SetDirection(Vec2::ZERO);
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

CBonusesType::ID GameScreen::GetIdTypeBonuses(const std::string & name)
{
	if (name == "MedPack")
	{
		return CBonusesType::MedicineChest;
	}
	else if (name == "GrenadeGun")
	{
		return CBonusesType::GrenadeGun;
	}
	else if (name == "PlasmaGun")
	{
		return CBonusesType::PlasmaGun;
	}
}