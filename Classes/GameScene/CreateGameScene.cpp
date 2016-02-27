#include "GameScene.h"

using namespace cocos2d;

void GameScreen::CreateTypesLifeObjects()
{
typesLifeObjects[TypeLifeObject::Player].SetTexture()
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

	playerSprite = Sprite::create(TypePlayer::TEXTURE_NAME, Rect(0, 0, 40, 40));// TODO : replace on const
	playerSprite->setPositionX(visibleSize.width / 2);
	playerSprite->setPositionY(visibleSize.height - playerSprite->getContentSize().height + origin.y);

	this->addChild(playerSprite, -1);
}
