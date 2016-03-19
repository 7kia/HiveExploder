#include "LifeObjects.h"

using namespace cocos2d;

CLifeObject::CLifeObject()
{
	SetIdClass(idClass::LifeObject);
}

CLifeObject::~CLifeObject()
{
}

void CLifeObject::SetType(TypeLifeObject & setType)
{
	type = &setType;

	setTexture(type->GetTexture());
	setTextureRect(type->GetRectangle());

	CreateCollision();

	SetVelocity(type->GetVelocity());

	m_health.SetValue(type->GetHealth());
}

void CLifeObject::CreateCollision()
{
	CCollision* body = CCollision::create(type->GetRectangle().size.width / 2);// PhysicsBody::createCircle(getContentSize().width / 2);
	body->setCollisionBitmask(1);
	body->setContactTestBitmask(Collision::BITMASK_LIFEOBJECT);
	body->SetMaster(this);

	setPhysicsBody(body);
}

void CLifeObject::Attack()
{
}
