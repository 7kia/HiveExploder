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
		PlasmaGun,
		AmountIDs
	};
public:
	void										SetAction(std::function<void(CLifeObject & master)> action);
	std::function<void(CLifeObject &)>			GetAction() const;
	// TODO : there not enough functional

	void										SetDeathSounds(std::vector<std::string> & nameSound);
	const std::vector<std::string>&				GetDeathSounds() const;
private:
	std::function<void(CLifeObject &)>	m_action;
	std::vector<std::string>			m_nameDeathSound;
};