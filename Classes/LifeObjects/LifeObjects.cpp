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

	SetCollision();

	SetVelocity(type->GetVelocity());

	health.SetValue(type->GetHealth());
}

void CLifeObject::SetCollision()
{
	CCollision* body = CCollision::create(type->GetRectangle().size.width / 2);// PhysicsBody::createCircle(getContentSize().width / 2);
	body->setCollisionBitmask(1);
	body->setContactTestBitmask(Collision::BITMASK_LIFEOBJECT);
	body->SetMaster(this);

	setPhysicsBody(body);
}

bool CLifeObject::GetStateDeath() const
{
	return isDeath;
}

void CLifeObject::SetHealth(int value)
{
	health.SetValue(value);
}

void CLifeObject::AddHealth(int value)
{
	health.AddToValue(value);
}

int CLifeObject::GetHealth() 
{
	return health.GetValue();
}

int CLifeObject::GetDamage() 
{
	return m_damage.GetValue();
}

void CLifeObject::Attack()
{
}
