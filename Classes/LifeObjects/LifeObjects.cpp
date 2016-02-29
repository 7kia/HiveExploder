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

	auto body = PhysicsBody::createCircle
		(visual.GetSprite()->getContentSize().width / 2);
	//body->setContactTestBitmask(true);
	//body->setDynamic(false);
	visual.GetSprite()->setPhysicsBody(body);


	SetVelocity(type->GetVelocity());

	health.SetValue(type->GetHealth());
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
