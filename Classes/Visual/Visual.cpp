#include "Visual.h"

using namespace cocos2d;

<<<<<<< dev
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

=======
>>>>>>> local
void CVisual::Move(cocos2d::Vec2 shiftVector)
{
	Vec2 currentPos = getPosition();
	currentPos += shiftVector;

<<<<<<< dev
	sprite->setPosition(currentPos);
}

std::shared_ptr<cocos2d::Sprite>  CVisual::GetSprite()
{
	return sprite;
}

void CVisual::SetSprite(std::shared_ptr<cocos2d::Sprite> setSprite)
{
	sprite = setSprite;
}
=======
	setPosition(currentPos);
}
>>>>>>> local
