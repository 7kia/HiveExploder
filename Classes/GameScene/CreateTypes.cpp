#include "CreateTypes.h"

using namespace cocos2d;
using namespace std;

void GameScreen::CreateTypesLifeObjects()
{
	CreateTypeLifeObject(TypeLifeObject::Player
		, "MARINE"
		, "MARINE_RECT"
		, "MARINE_MOVE_TIME"
		, "MARINE_ATTACK_TIME"
		, 250.f
		, 400.f
		, 600
		, CTypeWeapon::MarineWeapon
		, "MARINE_DEATH"
		, "DEATH"
		, CEffectType::ID::MarineDeath);


	CreateTypeLifeObject(TypeLifeObject::Zergling
		, "ZERGLING"
		, "ZERGLING_RECT"
		, "ZERGLING_MOVE_TIME"
		, "ZERGLING_ATTACK_TIME"
		, 80.f
		, 600.f
		, 35
		, CTypeWeapon::ZerglingWeapon
		, "ZERGLING_DEATH"
		, "DEATH"
		, CEffectType::ID::ZerglingDeath);

	CreateTypeLifeObject(TypeLifeObject::Hydralisk
		, "HYDRALISK"
		, "HYDRALISK_RECT"
		, "HYDRALISK_MOVE_TIME"
		, "HYDRALISK_ATTACK_TIME"
		, 80.f
		, 600.f
		, 180
		, CTypeWeapon::HydraliskWeapon
		, "HYDRALISK_DEATH"
		, "DEATH"
		, CEffectType::ID::HydraliskDeath);
}

void GameScreen::CreateTypeLifeObject(TypeLifeObject::ID id
	, const std::string & textureName
	, const std::string & nameRectangle
	, const std::string & timeMoveAnimation
	, const std::string & timeAttackAnimation
	, const float velocity
	, const float visionRange
	, const int health
	, CTypeWeapon::ID idWeapon
	, const std::string & nameDeathSounds
	, const std::string & nameDeathSoundFeatures
	, CEffectType::ID idEffectDeath)
{
	Texture2D* texture = Director::getInstance()->getTextureCache()->addImage(m_texturePaths[textureName]);

	m_typesLifeObjects[id].SetId(id);
	m_typesLifeObjects[id].SetTexture(texture);
	m_typesLifeObjects[id].SetTextureRect(m_rectanglePaths[nameRectangle]);

	m_typesLifeObjects[id].SetVelocity(velocity);
	m_typesLifeObjects[id].SetVisionRange(visionRange);
	m_typesLifeObjects[id].SetHealth(health);
	m_typesLifeObjects[id].SetWeapon(m_typesWeapons[idWeapon]);

	m_typesLifeObjects[id].SetMoveAnimations(CreateMoveAnimations(m_texturePaths[textureName]
																, m_rectanglePaths[nameRectangle]
																, m_timeAnimations[timeMoveAnimation]));

	m_typesLifeObjects[id].SetAttackAnimations(CreateAttackAnimations(m_texturePaths[textureName]
																	, m_rectanglePaths[nameRectangle]
																	, m_timeAnimations[timeAttackAnimation]));

	m_typesLifeObjects[id].SetSounds("DEATH", m_soundsPaths[nameDeathSounds]);
	m_typesLifeObjects[id].SetSoundsFeatures(m_soundsFeatures[nameDeathSoundFeatures]);
	m_typesLifeObjects[id].SetIdDeathEffect(idEffectDeath);

}


void GameScreen::CreateTypesShoots()
{
	CreateTypeShoot(CShootType::MarineShoot
		, "MARINE_SHOOT"
		, "MARINE_SHOOT_RECT"
		, CEffectType::ID::None);

	CreateTypeShoot(CShootType::HydraliskShoot
		, "HYDRALISK_SHOOT"
		, "HYDRALISK_SHOOT_RECT"
		, CEffectType::ID::None);

	CreateTypeShoot(CShootType::Grenade
		, "GRENADE"
		, "GRENADE_RECT"
		, CEffectType::ID::GrenadeShootDeath);

	CreateTypeShoot(CShootType::Plasma
		, "PLASMA_SHOOT"
		, "PLASMA_SHOOT_RECT"
		, CEffectType::ID::PlasmaShootDeath);

	CreateTypeShoot(CShootType::MeleeShoot
		, "MELEE_SHOOT"
		, "MELEE_SHOOT_RECT"
		, CEffectType::ID::None);
}


void GameScreen::CreateTypeShoot(CShootType::ID id
	, const std::string & textureName
	, const std::string & nameRectangle
	, CEffectType::ID idEffectDeath)
{
	Texture2D* texture = Director::getInstance()->getTextureCache()->addImage(m_texturePaths[textureName]);

	m_typesShoots[id].SetTexture(texture);
	m_typesShoots[id].SetTextureRect(m_rectanglePaths[nameRectangle]);

	m_typesShoots[id].SetIdDeathEffect(idEffectDeath);
}


void GameScreen::CreateTypesWeapons()
{
	CreateTypeWeapon(CTypeWeapon::MarineWeapon
		, 6
		, 0.25f
		, CShootType::MarineShoot
		, 750.f
		, 400.f
		, "MARINE_SHOOT"
		, "LAUNCH");

	CreateTypeWeapon(CTypeWeapon::ZerglingWeapon
		, 15
		, 1.0f
		, CShootType::MeleeShoot
		, 750.f
		, 80.f
		, "ZERGLING_SHOOT"
		, "LAUNCH");

	CreateTypeWeapon(CTypeWeapon::HydraliskWeapon
		, 12
		, 1.0f
		, CShootType::HydraliskShoot
		, 750.f
		, 400.f
		, "HYDRALISK_SHOOT"
		, "LAUNCH");

	CreateTypeWeapon(CTypeWeapon::GrenadeGun
		, 40
		, 1.0f
		, CShootType::Grenade
		, 750.f
		, 400.f
		, "GRENADE_SHOOT"
		, "LAUNCH");

	CreateTypeWeapon(CTypeWeapon::PlasmaGun
		, 50
		, 0.5f
		, CShootType::Plasma
		, 750.f
		, 400.f
		, "PLASMA_SHOOT"
		, "LAUNCH");
}

void GameScreen::CreateTypeWeapon(CTypeWeapon::ID id
	, const int damage
	, const float timeReload
	, CShootType::ID idShooteType
	, const float velocity
	, const float distanse
	, const std::string & nameSounds
	, const std::string & nameSoundFeatures)
{
	m_typesWeapons[id].SetId(id);
	m_typesWeapons[id].SetDamage(damage);
	m_typesWeapons[id].SetTime(timeReload);
	m_typesWeapons[id].SetTypeShoot(m_typesShoots[idShooteType]);// TODO : replace
	m_typesWeapons[id].SetVelocity(velocity);
	m_typesWeapons[id].SetDistanse(distanse);

	m_typesWeapons[id].SetSounds("LAUNCH", m_soundsPaths.at(nameSounds));
	m_typesWeapons[id].SetSoundsFeatures(m_soundsFeatures[nameSoundFeatures]);
}


void GameScreen::CreateTypesBonuses()
{
	CreateTypeBonus(CBonusesType::MedicineChest
		, "BONUS_MED_PACK"
		, "BONUS_RECT"
		, "BONUS_ACTIVATE"
		, "ACTIVATE");

	CreateTypeBonus(CBonusesType::GrenadeGun
		, "BONUS_GRENADE_GUN"
		, "BONUS_RECT"
		, "BONUS_ACTIVATE"
		, "ACTIVATE");

	CreateTypeBonus(CBonusesType::PlasmaGun
		, "BONUS_PLASMA_GUN"
		, "BONUS_RECT"
		, "BONUS_ACTIVATE"
		, "ACTIVATE");
}

void GameScreen::CreateTypeBonus(CBonusesType::ID id
	, const std::string & textureName
	, const std::string & nameRectangle
	, const std::string & nameSounds
	, const std::string & nameSoundFeatures)
{
	Texture2D* texture = Director::getInstance()->getTextureCache()->addImage(m_texturePaths[textureName]);

	m_typeBonuses[id].SetTexture(texture);
	m_typeBonuses[id].SetTextureRect(m_rectanglePaths[nameRectangle]);
	m_typeBonuses[id].SetAction(m_functions_for_bonuses[id]);

	m_typeBonuses[id].SetSounds("DEATH", m_soundsPaths[nameSounds]);
	m_typeBonuses[id].SetSoundsFeatures(m_soundsFeatures[nameSoundFeatures]);
}


void GameScreen::CreateTypesEffects()
{
	CreateTypeEffect(CEffectType::MarineDeath
					, "MARINE_DEATH"
					, "MARINE_DEATH_RECT"
					, "MARINE_DEATH_TIME"
					, "MARINE_DEATH_TIME");

	CreateTypeEffect(CEffectType::ZerglingDeath
					, "ZERGLING_DEATH"
					, "ZERGLING_DEATH_RECT"
					, "ZERGLING_DEATH_TIME"
					, "ZERGLING_DEATH_TIME");

	CreateTypeEffect(CEffectType::HydraliskDeath
					, "HYDRALISK_DEATH"
					, "HYDRALISK_DEATH_RECT"
					, "HYDRALISK_DEATH_TIME"
					, "HYDRALISK_DEATH_TIME");

	CreateTypeEffect(CEffectType::GrenadeShootDeath
					, "GRENADE_SHOOT_DEATH"
					, "GRENADE_SHOOT_DEATH_RECT"
					, "GRENADE_SHOOT_DEATH_TIME"
					, "GRENADE_SHOOT_DEATH_TIME");

	CreateTypeEffect(CEffectType::PlasmaShootDeath
					, "PLASMA_SHOOT_DEATH"
					, "PLASMA_SHOOT_DEATH_RECT"
					, "PLASMA_SHOOT_DEATH_TIME"
					, "PLASMA_SHOOT_DEATH_TIME");

}

void GameScreen::CreateTypeEffect(CEffectType::ID id
								, const std::string & textureName
								, const std::string & nameRectangle
								, const std::string & timeLive
								, const std::string & timeAnimation)
{
	Texture2D* texture = Director::getInstance()->getTextureCache()->addImage(m_texturePaths[textureName]);
	m_typeEffects[id].SetTexture(texture);
	m_typeEffects[id].SetTextureRect(m_rectanglePaths[nameRectangle]);
	m_typeEffects[id].SetLifeTime(m_timeLiveEffects[timeLive]);
	m_typeEffects[id].SetAnimations(CreateEffectAnimations(m_texturePaths[textureName]
		, m_rectanglePaths[nameRectangle]
		, m_timeAnimations[timeAnimation]));

}
