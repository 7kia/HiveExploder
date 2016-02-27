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

float CVisual::GetPosition(IDCoordinate id) const
{
	switch (id) {
	case CVisual::IDCoordinate::X:
		return sprite->getPosition().x;
	case CVisual::IDCoordinate::Y:
		return sprite->getPosition().y;
	default:
		break;
	}

}

cocos2d::Vec2 CVisual::GetPosition() const
{
	return sprite->getPosition();
}

void CVisual::Move(cocos2d::Vec2 shiftVector)
{
	Vec2 currentPos = sprite->getPosition();
	currentPos += shiftVector;

	sprite->setPosition(currentPos);
}