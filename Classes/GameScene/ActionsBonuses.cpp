#include "ActionsBonuses.h"

void GameScreen::CreateFunctionsForBonuses()
{
	// TODO : replace functions
	m_functions_for_bonuses[CBonusesType::GrenadeGun] = [&](CLifeObject & object)
	{
		object.SetWeapon(m_typesWeapons[CTypeWeapon::ID::GrenadeGun]);
	};

	m_functions_for_bonuses[CBonusesType::PlasmaGun] = [&](CLifeObject & object) {
		object.SetWeapon(m_typesWeapons[CTypeWeapon::ID::PlasmaGun]);
	};

	m_functions_for_bonuses[CBonusesType::MedicineChest] = [&](CLifeObject & object) {
		object.AddHealth(GameSceneRecourses::MED_PACK_ADD_HEALTH);
	};


}

void GameScreen::ReplaceWeaponOnGrenadeGun(CLifeObject & object)
{
	object.SetWeapon(m_typesWeapons[CTypeWeapon::ID::GrenadeGun]);
}

void GameScreen::ReplaceWeaponOnPlasmaGun(CLifeObject & object)
{
	object.SetWeapon(m_typesWeapons[CTypeWeapon::ID::PlasmaGun]);
}

void GameScreen::GetMedPack(CLifeObject & object)
{
	object.AddHealth(GameSceneRecourses::MED_PACK_ADD_HEALTH);
}

