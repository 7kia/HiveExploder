#include "Collision.h"

CCollision::CCollision(float radius) : PhysicsBody()
{
	//addShape(PhysicsBody::createCircle(radius), true);
	//addShape(cocos2d::PhysicsShape::se)
	//addShape()
	
}

CCollision* CCollision::create(float radius)
{
	//CCollision * body = new(std::nothrow) CCollision(radius);
	CCollision * body = static_cast<CCollision*>(PhysicsBody::createCircle(radius));

	if (body) {
		body->init();
		body->autorelease();
		body->setDynamic(true);
		return body;
	}
	CC_SAFE_DELETE(body);
	return NULL;
}

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
