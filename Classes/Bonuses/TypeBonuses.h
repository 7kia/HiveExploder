#pragma once

#include "../LifeObjects/LifeObjects.h"

class CBonusesType :
	public CVisualDataType
{
public:
	enum ID
	{
		MedicineChest = 0,
		GrenadeGun,
		PlasmaGaun,
		AmountIDs
	};
public:
	void										SetAction(std::function<void(CLifeObject & master)> action);
	// TODO : there not enough functional
private:
	std::function<void(CLifeObject & master)>	m_action;
};