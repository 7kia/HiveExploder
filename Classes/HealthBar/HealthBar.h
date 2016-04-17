#pragma once

#include "../Entity/Entity.h"

class CLifeObject;

class CBar :
	public CEntity
{
public:
	CBar();
	CBar & operator=(const CBar & right);
	CBar(cocos2d::Texture2D *texture, const cocos2d::Rect & rectangle);
	//CShoot(const CShoot& copy);
	virtual ~CBar() override;

	static CBar* create();
	//CREATE_FUNC(CShoot);

	//bool init() override;
	virtual void cleanup() override;

	void				update(float dt) override;

	void				SetMaster(CLifeObject & master);
	CLifeObject&		GetMaster();// TOOD : see need there const
private:
	void				SetTextureRect();
	void				UpdatePosition();
private:
	CLifeObject*		m_master;
};
