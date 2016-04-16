#pragma once

#include "TypeBonuses.h"

class CBonus: public CEntity
{
public:
	CBonus();
	//CShoot(const CShoot& copy);
	~CBonus();

	void									SetType(const CBonusesType &defineType);
	const CBonusesType&						GetType();

	void									update(float dt) override;
	void									CreateCollision();
	void									ApplyAction(CLifeObject & object);

	void									SetStateDestroy();
	bool									GetState();
private:
	std::shared_ptr<const CBonusesType>		m_type;
	bool									m_is_destoroy = false;
};