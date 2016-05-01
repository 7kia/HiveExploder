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
	m_manageCirlce.SetSprite(Sprite::create(m_texturePaths["MANAGE_CIRCLE"]));

	this->addChild(m_manageCirlce.GetSprite(), m_gameIntConstats["levelInterface"]);
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
	m_tileMap = CCTMXTiledMap::create(m_texturePaths["MAP"]);

	CCTMXLayer *m_collisionLayer = m_tileMap->layerNamed("Collision");
	m_collisionLayer->setVisible(false);

	this->addChild(m_tileMap, m_gameIntConstats["levelMap"]);
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



		addChild(spriteWall, m_gameIntConstats["levelObjects"]);
	}


}

void GameScreen::CreateLifeObjects()
{
	// TODO : redesign
	Texture2D* textureHealthBar = Director::getInstance()->getTextureCache()->addImage(m_texturePaths["HEALTH_BAR"]);

	CBar healthBar(textureHealthBar, m_rectanglePaths["HEALTH_BAR_RECT"]);
	/////////////////

	ValueVector objects = m_tileMap->getObjectGroup("LifeObjects")->getObjects();

	ValueMap value;
	for (const auto& object : objects)
	{
		value = object.asValueMap();
		
		CLifeObject* lifeObjects = new CLifeObject();
		lifeObjects->SetType(m_typesLifeObjects[GetIdTypeLifeObject(value["name"].asString())]);

		lifeObjects->setPosition(value["x"].asFloat(),
								value["y"].asFloat());

		healthBar.SetMaster(*lifeObjects);
		lifeObjects->SetHealthBar(healthBar);

		m_lifeObjects.push_back(lifeObjects);

		addChild(lifeObjects, m_gameIntConstats["levelObjects"]);
		addChild(&lifeObjects->GetHealthBar(), m_gameIntConstats["levelObjects"]);

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
		addChild(bonus, m_gameIntConstats["levelObjects"]);
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
	scene->addChild(shoot, scene->m_gameIntConstats["levelObjects"]);

	// TODO
	scene->PlayRandomSound(m_weapon.GetType().GetSounds("LAUNCH"), scene->m_soundsFeatures["LAUNCH"]);

	m_weapon.SetState(CWeapon::IdState::NotActive);
	m_weapon.ResetTimer();
	SetDirection(Vec2::ZERO);
}

void GameScreen::CreateEffect(CEffectType::ID id, Vec2 position)
{
	if (id != CEffectType::ID::None)
	{
		CEffect* newEffect = new CEffect();

		newEffect->SetType(m_typeEffects[id]);
		newEffect->setPosition(position);

		m_effects.push_back(newEffect);

		addChild(newEffect, m_gameIntConstats["levelObjects"]);
	}
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