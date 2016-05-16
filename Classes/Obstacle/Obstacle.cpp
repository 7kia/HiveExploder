#include "Obstacle.h"


using namespace cocos2d;

CObstacle::CObstacle() : CEntity()
{
	this->SetIdClass(idClass::Obstacle);
	CEntity::init();
}


CObstacle::~CObstacle()
{
}


void CObstacle::cleanup()
{
}

void CObstacle::SetType(CObstacleType defineType)
{
	m_typeObstacle = defineType;
}

CObstacle::CObstacleType CObstacle::GetType()
{
	return m_typeObstacle;
}

void CObstacle::update(float dt)
{
}

void CObstacle::CreateCollision(const std::vector<cocos2d::Vec2>& vertex)
{
	CCollision* body = CCollision::createEdgePolygon(vertex.data()
													, vertex.size()
													, PhysicsMaterial(0.1f, 1.f, 0.f)
													, 2.f);//CCollision::createCircle(getContentSize().width / 2);
	//delete arrayVertex;// TODO : DANGER !!!
	//arrayVertex = nullptr;
	
	body->setCollisionBitmask(1);
	body->setContactTestBitmask(Collision::BITMASK_LIFEOBJECT);
	body->SetMaster(this);
	body->setDynamic(false);

	setPhysicsBody(body);



}
