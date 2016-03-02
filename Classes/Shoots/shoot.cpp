#include "shoot.h"

using namespace cocos2d;

void CShoot::SetType(TypeShoot &defineType)
{
	type = &defineType;

	visual.SetTexture(type->GetTexture());
	visual.SetTextureRect(type->GetRectangle());
}

const TypeShoot& CShoot::GetType()
{
	return *type;
}

int CShoot::GetDamage(int id)
{
	//assert(g_Functions::checkDiaposon(id , RESET_VALUE , amountTypeDamage));
	return damage.GetValue();
}

cocos2d::Sprite* CShoot::GetSprite()
{
	return visual.GetSprite();
}

void CShoot::SetSprite(Sprite * setSprite)
{
	visual.SetSprite(setSprite);
}

void CShoot::SetStartPlace(Vec2 pos, Vec2 direction,
							Size sizeShooter)
{
	Vec2 shiftBullet = direction;
	shiftBullet.x *= sizeShooter.width * COEFFICIENT_SHIFT_BULLET_FROM_SHOOTER;
	shiftBullet.y *= sizeShooter.height * COEFFICIENT_SHIFT_BULLET_FROM_SHOOTER;
	SetPosition(pos + shiftBullet);
}