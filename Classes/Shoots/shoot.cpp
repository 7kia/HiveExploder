#include "shoot.h"

using namespace cocos2d;

CShoot::CShoot() : CVisual()
{
}

CShoot::~CShoot()
{
}

CShoot * CShoot::create()
{
	CShoot * sprite = new(std::nothrow) CShoot();
	if (sprite) {
		sprite->init();
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return NULL;
}

void CShoot::SetType(TypeShoot &defineType)
{
	type = &defineType;

	setTexture(type->GetTexture());
	setTextureRect(type->GetRectangle());

	SetCollision();

	velocity = type->GetVelocity();
}

const TypeShoot& CShoot::GetType()
{
	return *type;
}

void CShoot::Update(float dt)
{
	Move(direction, dt);

	velocity *= (1 - COEFFECIENT_SLOW_BULLET);
}

int CShoot::GetDamage(int id)
{
	//assert(g_Functions::checkDiaposon(id , RESET_VALUE , amountTypeDamage));
	return damage.GetValue();
}


void CShoot::SetRotation(Vec2 directionShooter)
{
	float rotate = CC_RADIANS_TO_DEGREES(directionShooter.getAngle(VECTOR_VERTICAL_UP));
	setRotation(rotate);
}

void CShoot::SetStartPlace(Vec2 pos, Vec2 directionShooter,
							Size sizeShooter)
{
	direction = directionShooter;
	Vec2 shiftBullet = direction;
	shiftBullet.x *= sizeShooter.width * COEFFICIENT_SHIFT_BULLET_FROM_SHOOTER;
	shiftBullet.y *= sizeShooter.height * COEFFICIENT_SHIFT_BULLET_FROM_SHOOTER;
	setPosition(pos + shiftBullet);
	SetRotation(directionShooter);
}


void CShoot::SetCollision()
{
	auto body = PhysicsBody::createCircle(getContentSize().width / 2);
	body->setCollisionBitmask(1);
	body->setContactTestBitmask(Collision::BITMASK_SHOOT);
	setPhysicsBody(body);
}