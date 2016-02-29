#include "GameScene.h"

using namespace cocos2d;

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
	auto textureMarineShoot = Director::getInstance()->getTextureCache()->addImage(GameSceneTexture::PATH_TEXTURE
																					+ GameSceneTexture::MARINE_SHOOT);

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

	auto sprite = Sprite::create();
	lifeObjects[0].SetSprite(sprite);
	lifeObjects[0].SetType(typesLifeObjects[TypeLifeObject::Player]);
	lifeObjects[0].SetPosition(visibleSize.width / 2 + origin.x,
								visibleSize.height / 2 + origin.y);


	this->addChild(lifeObjects[0].GetSprite(), -1);
}

void GameScreen::CreateEnemys()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	auto sprite = Sprite::create();
	lifeObjects[1].SetSprite(sprite);
	lifeObjects[1].SetType(typesLifeObjects[TypeLifeObject::Zergling]);
	lifeObjects[1].SetPosition(visibleSize.width / 2 + origin.x,
								visibleSize.height / 2 + origin.y + visibleSize.height / 4);


	this->addChild(lifeObjects[1].GetSprite(), -1);
}

void GameScreen::CreateContactListener()
{
	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(GameScreen::OnContactBegin, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);
}
