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

	static	 CCollision* create(float radius);
	static	CCollision * createEdgePolygon(const cocos2d::Vec2 * points
												, int count
												, const cocos2d::PhysicsMaterial & material
												, float border);
	//CREATE_FUNC(CCollision);

	static CCollision* createBox(const cocos2d::Size& size
								, const cocos2d::PhysicsMaterial& material = cocos2d::PHYSICSBODY_MATERIAL_DEFAULT
								, const cocos2d::Vec2& offset = cocos2d::Vec2::ZERO);


	void			SetMaster(CEntity* master);
	CEntity* GetMaster();
private:
	//std::unique_ptr<CEntity> m_master;
	CEntity* m_master;
};