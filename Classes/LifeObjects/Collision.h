#pragma once

#include "cocos2d.h"

typedef cocos2d::Vec2 Direction;

namespace Collision
{
	static const int BITMASK_LIFEOBJECT = 0x01;
	static const int BITMASK_SHOOT = 0x02;
}

class CEntity;

class CCollision : public cocos2d::PhysicsBody
{
public:
	CCollision();
	virtual ~CCollision() override;

	static CCollision* create(float radius);
	//CREATE_FUNC(CCollision);

	void			SetMaster(CEntity* master);
	CEntity* GetMaster();
private:
	//std::unique_ptr<CEntity> m_master;
	CEntity* m_master;
};