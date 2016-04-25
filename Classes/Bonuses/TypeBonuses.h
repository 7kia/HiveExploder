#pragma once

#include "../LifeObjects/LifeObjects.h"

class CBonusesType :
	public CVisualDataType
	, public CSoundDataType
{
public:
	enum ID
	{
		MedicineChest = 0,
		GrenadeGun,
		PlasmaGun,
		AmountIDs
	};
public:
	void										SetAction(std::function<void(CLifeObject & master)> action);
	std::function<void(CLifeObject &)>			GetAction() const;
	// TODO : there not enough functional
private:
	std::function<void(CLifeObject &)>	m_action;
};