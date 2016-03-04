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

	// TODO : redesign
	auto body = PhysicsBody::createCircle
		(visual.GetSprite()->getContentSize().width / 2);
	body->setCollisionBitmask(1);
	body->setContactTestBitmask(true);
	//body->setDynamic(false);
	//body->setMass(INFINITY);
	visual.GetSprite()->setPhysicsBody(body);


	SetVelocity(type->GetVelocity());

	health.SetValue(type->GetHealth());
}

std::shared_ptr<cocos2d::Sprite>  CLifeObject::GetSprite()
{
	return visual.GetSprite();
}

void CLifeObject::SetSprite(std::shared_ptr<cocos2d::Sprite>  setSprite)
{
	visual.SetSprite(setSprite);
}

bool CLifeObject::GetStateDeath() const
{
	return isDeath;
}

void CLifeObject::Attack()
{
}
