#include "LifeObjects.h"

using namespace cocos2d;

CLifeObject::CLifeObject()
{
}

CLifeObject::~CLifeObject()
{
}

void CLifeObject::SetType(TypeLifeObject & setType)
{
	type = &setType;

	visual.SetTexture(type->GetTexture());
	visual.SetTextureRect(type->GetRectangle());

	SetVelocity(type->GetVelocity());
}

cocos2d::Sprite* CLifeObject::GetSprite()
{
	return visual.GetSprite();
}

void CLifeObject::SetSprite(cocos2d::Sprite * setSprite)
{
	visual.SetSprite(setSprite);
}

bool CLifeObject::GetStateDeath() const
{
	return isDeath;
}
