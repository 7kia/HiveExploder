#include "Visual.h"

using namespace cocos2d;

void CVisual::SetTexture(cocos2d::Texture2D* texture)
{
	sprite->setTexture(texture);
}

void CVisual::SetTextureRect(cocos2d::Rect rectangle)
{
	sprite->setTextureRect(rectangle);
}

cocos2d::Rect CVisual::GetGlobalBounds() const
{
	return sprite->getBoundingBox();
}

void CVisual::SetOrigin(cocos2d::Vec2 setOrigin)
{
	sprite->setAnchorPoint(setOrigin);
}

void CVisual::SetPosition(cocos2d::Vec2 pos)
{
	sprite->setPosition(pos);
}

void CVisual::SetPosition(float x, float y)
{
	sprite->setPosition(x, y);
}

float CVisual::GetPositionX() const
{
	return sprite->getPosition().x;
}

float CVisual::GetPositionY() const
{
	return sprite->getPosition().y;
}

cocos2d::Vec2 CVisual::GetPosition() const
{
	return sprite->getPosition();
}

void CVisual::SetRotation(float rotate)
{
	sprite->setRotation(rotate);
}

void CVisual::Move(cocos2d::Vec2 shiftVector)
{
	Vec2 currentPos = sprite->getPosition();
	currentPos += shiftVector;

	sprite->setPosition(currentPos);
}

cocos2d::Sprite* CVisual::GetSprite()
{
	return sprite;
}

void CVisual::SetSprite(Sprite* setSprite)
{
	sprite = setSprite;
}
