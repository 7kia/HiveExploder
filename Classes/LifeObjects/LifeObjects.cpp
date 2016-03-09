#include "LifeObjects.h"

using namespace cocos2d;

CLifeObject::CLifeObject() : CEntity()
{
}

CLifeObject::~CLifeObject()
{
}



CLifeObject * CLifeObject::create()
{
	CLifeObject * lifeObject = new(std::nothrow) CLifeObject;
	if (lifeObject) {
		
		//!!!!!!!!!TODO
		lifeObject->init();
		lifeObject->SetIdClass(idClass::LifeObject);		

		return lifeObject;
	}
	CC_SAFE_DELETE(lifeObject);
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


void CLifeObject::SetCollision()
{
	auto body = CCollision::create(type->GetRectangle().size.width / 2);// PhysicsBody::createCircle(getContentSize().width / 2);
	body->setCollisionBitmask(1);
	body->setContactTestBitmask(Collision::BITMASK_LIFEOBJECT);
	body->SetMaster(this);
	setPhysicsBody(body);

}

bool CLifeObject::GetStateDeath() const
{
	return isDeath;
}

void CLifeObject::Attack()
{
}
