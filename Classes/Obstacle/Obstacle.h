#pragma once

#include "../Entity/Entity.h"

class CObstacle :
	public CEntity
{
public:
	CObstacle();
	//CShoot(const CShoot& copy);
	virtual ~CObstacle() override;

	enum class CObstacleType
	{
			Wall = 0
		,	Water
	};
public:

	static CObstacle* create();
	//CREATE_FUNC(CShoot);

	//bool init() override;
	virtual void cleanup() override;

	void								SetType(CObstacleType defineType);
	CObstacleType						GetType();

	void								update(float dt) override;

	void								CreateCollision(cocos2d::Size size, float angle);
private:
	CObstacleType						m_typeObstacle = CObstacleType::Wall;
};