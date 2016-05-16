#include "Collision.h"

using namespace cocos2d;

CCollision::CCollision() : PhysicsBody()
{
	
}

CCollision* CCollision::create(float radius)
{
	CCollision * body = new(std::nothrow) CCollision();

	if (body && body->PhysicsBody::init()) {
		body->addShape(PhysicsShapeCircle::create(radius, PhysicsMaterial(0.1f, 1.f, 0.f), Vec2::ZERO));
		body->autorelease();
		body->setDynamic(true);
		return body;
	}
	CC_SAFE_DELETE(body);
	return NULL;
}

CCollision* CCollision::createEdgePolygon(const Vec2* points, int count, const PhysicsMaterial& material, float border)
{
	CCollision * body = new(std::nothrow) CCollision();

	if (body && body->PhysicsBody::init()) {
		body->addShape(PhysicsShapeEdgePolygon::create(points, count, material, border));
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
