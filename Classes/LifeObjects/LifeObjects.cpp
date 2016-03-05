#include "LifeObjects.h"

using namespace cocos2d;

CLifeObject::CLifeObject() : CVisual()
{
}

CLifeObject::~CLifeObject()
{
}



CLifeObject * CLifeObject::create()
{
	CLifeObject * sprite = new CLifeObject;
	if (sprite) {
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return NULL;
}

void CLifeObject::SetType(TypeLifeObject & setType)
{
	type = &setType;

	setTexture(type->GetTexture());
	setTextureRect(type->GetRectangle());

	SetCollision();

	SetVelocity(type->GetVelocity());

	health.SetValue(type->GetHealth());
}

<<<<<<< dev
std::shared_ptr<cocos2d::Sprite>  CLifeObject::GetSprite()
{
	return visual.GetSprite();
}

void CLifeObject::SetSprite(std::shared_ptr<cocos2d::Sprite>  setSprite)
{
	visual.SetSprite(setSprite);
=======
void CLifeObject::SetCollision()
{
	auto body = PhysicsBody::createCircle(getContentSize().width / 2);
	body->setCollisionBitmask(1);
	body->setContactTestBitmask(Collision::BITMASK_LIFEOBJECT);
	setPhysicsBody(body);
>>>>>>> local
}

bool CLifeObject::GetStateDeath() const
{
	return isDeath;
}

void CLifeObject::Attack()
{
}
