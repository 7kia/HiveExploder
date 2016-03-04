#include "shoot.h"

using namespace cocos2d;

void CShoot::SetType(TypeShoot &defineType)
{
	type = &defineType;

	visual.SetTexture(type->GetTexture());
	visual.SetTextureRect(type->GetRectangle());

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
	visual.SetRotation(rotate);
}

cocos2d::Sprite* CShoot::GetSprite()
{
	return visual.GetSprite();
}

void CShoot::SetSprite(Sprite * setSprite)
{
	visual.SetSprite(setSprite);
}

void CShoot::SetStartPlace(Vec2 pos, Vec2 directionShooter,
							Size sizeShooter)
{
	direction = directionShooter;
	Vec2 shiftBullet = direction;
	shiftBullet.x *= sizeShooter.width * COEFFICIENT_SHIFT_BULLET_FROM_SHOOTER;
	shiftBullet.y *= sizeShooter.height * COEFFICIENT_SHIFT_BULLET_FROM_SHOOTER;
	SetPosition(pos + shiftBullet);
	SetRotation(directionShooter);
}