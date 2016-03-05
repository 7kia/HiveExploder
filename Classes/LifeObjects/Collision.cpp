#include "Collision.h"

using namespace cocos2d;

CCollision::CCollision() : PhysicsBody()
{
	
}

CCollision::CCollision(float radius) : PhysicsBody()// TODO : delete
{
	addShape(PhysicsShapeCircle::create(radius, PhysicsMaterial::PhysicsMaterial(), Vec2::ZERO));
}
///*


CCollision* CCollision::create(float radius)
{
	//CCollision * body = new(std::nothrow) CCollision(radius);
	CCollision * body = new CCollision();

	if (body && body->PhysicsBody::init()) {
		body->addShape(PhysicsShapeCircle::create(radius, PhysicsMaterial::PhysicsMaterial(), Vec2::ZERO));
		body->autorelease();
		body->setDynamic(true);
		return body;
	}
	CC_SAFE_DELETE(body);
	return NULL;
}
//*/


void CCollision::SetMaster(CEntity * master)
{
	m_master = master;
}

CEntity* CCollision::GetMaster()
{
	return m_master;
}

CCollision::~CCollision()
{
}
