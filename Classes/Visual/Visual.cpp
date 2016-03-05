#include "Visual.h"

using namespace cocos2d;

CVisual::CVisual()
{
	Sprite::init();
}

CVisual::~CVisual()
{
}

void CVisual::Move(cocos2d::Vec2 shiftVector)
{
	Vec2 currentPos = getPosition();
	currentPos += shiftVector;

	setPosition(currentPos);
}
