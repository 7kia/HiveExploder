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
	setTextureRect(type->GetTextureRectangle());

	CreateCollision();

	SetVelocity(type->GetVelocity());

	m_health.SetValue(type->GetHealth());

	m_weapon.SetType(type->GetTypeWeapon());

}

void CLifeObject::CreateCollision()
{
	CCollision* body = CCollision::create(type->GetTextureRectangle().size.width / 2);// PhysicsBody::createCircle(getContentSize().width / 2);
	body->setCollisionBitmask(1);
	body->setContactTestBitmask(Collision::BITMASK_LIFEOBJECT);
	body->SetMaster(this);

	setPhysicsBody(body);
}

void CLifeObject::Attack()
{
	if (m_weapon.GetState() == CWeapon::IdState::NotActive)
	{
		m_weapon.SetState(CWeapon::IdState::NotShoot);
	}
}

void CLifeObject::SetWeaponState(CWeapon::IdState state)
{
	m_weapon.SetState(state);
}

CWeapon::IdState CLifeObject::GetWeaponState() const
{
	return m_weapon.GetState();
}
