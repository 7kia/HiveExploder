#include "shoot.h"
#include "../Entity/Weapon.h"

using namespace cocos2d;

CShoot::CShoot() : CEntity()
{
	this->SetIdClass(idClass::Shoot);
	CEntity::init();
}

CShoot::~CShoot()
{
}

void CShoot::cleanup()
{
}

void CShoot::SetType(const CShootType &defineType)

{
	m_type.reset(&defineType);// = &;

	setTexture(m_type->GetTexture());
	setTextureRect(m_type->GetTextureRectangle());

	CreateCollision();

	m_damage.SetValue(m_weapon->GetDamage());
	m_velocity = m_weapon->GetVelocity();
}

const CShootType& CShoot::GetType()
{
	return *m_type;
}

void CShoot::update(float dt)
{
	Move(m_direction, dt);

	m_velocity *= (1 - COEFFECIENT_SLOW_BULLET);
}

int CShoot::GetDamage(int id)
{
	//assert(g_Functions::checkDiaposon(id , RESET_VALUE , amountTypeDamage));
	return m_damage.GetValue();
}

int CShoot::GetDamage()
{
	return m_damage.GetValue();
}

void CShoot::SetWeapon(const CWeapon & weapon)
{
	m_weapon = &weapon;
}

const CWeapon* CShoot::GetWeapon() const
{
	return m_weapon;
}

void CShoot::SetDirection(cocos2d::Vec2 directionShooter)
{
	float rotate = CC_RADIANS_TO_DEGREES(directionShooter.getAngle(VECTOR_VERTICAL_UP));
	setRotation(rotate);
}

void CShoot::SetStartPlace(Vec2 pos, Vec2 directionShooter,
							Size sizeShooter)
{
	m_direction = directionShooter;
	Vec2 shiftBullet = m_direction;
	shiftBullet.x *= sizeShooter.width * COEFFICIENT_SHIFT_BULLET_FROM_SHOOTER;
	shiftBullet.y *= sizeShooter.height * COEFFICIENT_SHIFT_BULLET_FROM_SHOOTER;

	setPosition(pos + shiftBullet);
	SetDirection(directionShooter);
}


void CShoot::CreateCollision()
{
	CCollision* body = CCollision::create(m_type->GetTextureRectangle().size.width / 2);//CCollision::createCircle(getContentSize().width / 2);
	body->setCollisionBitmask(1);
	body->setContactTestBitmask(Collision::BITMASK_SHOOT);
	body->SetMaster(this);

	setPhysicsBody(body);
}