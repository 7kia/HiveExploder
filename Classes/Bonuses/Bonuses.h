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
private:
	std::shared_ptr<const CBonusesType>		m_type;
};