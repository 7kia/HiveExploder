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
	m_type.reset(&setType);

	setTexture(m_type->GetTexture());
	setTextureRect(m_type->GetTextureRectangle());

	CreateCollision();

	SetVelocity(m_type->GetVelocity());

	m_health.SetValue(m_type->GetHealth());

	m_weapon.SetType(m_type->GetTypeWeapon());

}

void CLifeObject::CreateCollision()
{
	CCollision* body = CCollision::create(m_type->GetTextureRectangle().size.width / 2);// PhysicsBody::createCircle(getContentSize().width / 2);
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
