#include "Bonuses.h"

CBonus::CBonus() : CEntity()
{
	this->SetIdClass(idClass::Bonus);
	CEntity::init();
}

CBonus::~CBonus()
{
}

void CBonus::SetType(const CBonusesType & defineType)
{
	m_type.reset(&defineType);

	setTexture(m_type->GetTexture());
	setTextureRect(m_type->GetTextureRectangle());

	CreateCollision();
}

const CBonusesType & CBonus::GetType()
{
	return *m_type;
}

void CBonus::update(float dt)
{
	// TOOD : add code for animation
}


void CBonus::CreateCollision()
{
	CCollision* body = CCollision::create(m_type->GetTextureRectangle().size.width / 2);//CCollision::createCircle(getContentSize().width / 2);
	body->setCollisionBitmask(1);
	body->setContactTestBitmask(Collision::BITMASK_SHOOT);
	body->SetMaster(this);

	setPhysicsBody(body);
}

void CBonus::ApplyAction(CLifeObject & object)
{
	m_type->GetAction()(object);
}

void CBonus::SetStateDestroy()
{
	m_is_destoroy = true;
}

bool CBonus::GetState()
{
	return m_is_destoroy;
}
