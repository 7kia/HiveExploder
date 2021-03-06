#pragma once

#include "Config.h"
#include "ManageCircle.h"
#include "../LifeObjects/LifeObjects.h"
#include "../Shoots/shoot.h"
#include "../Entity/Weapon.h"
#include "../Bonuses/Bonuses.h"
#include "../HealthBar/HealthBar.h"
#include "../Effect/Effect.h"
#include "../Obstacle/Obstacle.h"
 
#include "SimpleAudioEngine.h"
#include <vector>
#include <string>
//#include "spine/json.h"
#include "json/document.h"
#include "json/writer.h"
#include "json/stringbuffer.h"


//
//#include "json_spirit/json_spirit.h"

#include <fstream>
#include <iostream>
#include <set>
//#include <unordered_map>

namespace GameSceneRecourses// TODO : redesign
{
	static const float SHIFT_FROM_FRAME = 1.f;
	static const float TIME_MOVE_ANIMATION_FRAME = 0.2f;

	static const int MED_PACK_ADD_HEALTH = 100;

}

typedef std::unordered_map<std::string, std::string> MapPath;
//typedef std::unordered_map<std::string, std::vector<std::string>> MapPaths;
typedef std::unordered_map<std::string, cocos2d::Rect> MapRect;
typedef std::unordered_map<std::string, int> MapInt;
typedef std::unordered_map<std::string, float> MapFloat;

typedef std::vector<std::string> Words;

class GameScreen : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameScreen);
    
    void					GoToPauseScene(Ref *pSender);
    void					GoToGameOverScene(Ref *pSender);
	void					GoToVictoryScene(cocos2d::Ref * pSender);
    
    void					update(float dt) override;
	void					ActivateActiveWeapons();
    
	bool					onTouchBegan(cocos2d::Touch *touch, cocos2d::Event * event) override;
	void					onTouchMoved(cocos2d::Touch *touch, cocos2d::Event * event) override;
	void					onTouchEnded(cocos2d::Touch *touch, cocos2d::Event * event) override;
	void					onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event * event) override;


	void					AddShoot(CShoot & addShoot);

	/////// XXXXXXXXXXXx
	void					SetPhysicsWorld(cocos2d::PhysicsWorld* world);
	bool					onContactBegin(cocos2d::PhysicsContact& contact);
	bool					onContactPreSolve(cocos2d::PhysicsContact& contact);
	////// XXXXXXXXXXXX
	// /
	// TODO : see need there private
	//
	//CC_SYNTHESIZE(cocos2d::CCTMXTiledMap*, m_tileMap, TileMap);

public:
	std::vector<CLifeObject*>			m_lifeObjects;
	std::vector<CShoot*>				m_shoots;
	std::vector<CBonus*>				m_bonuses;
	std::vector<CEffect*>				m_effects;

	TypeLifeObject						m_typesLifeObjects[TypeLifeObject::AmountIDs];
	CTypeWeapon							m_typesWeapons[CTypeWeapon::AmountIDs];
	CShootType							m_typesShoots[CShootType::AmountIDs];
	CBonusesType						m_typeBonuses[CBonusesType::AmountIDs];
	CEffectType							m_typeEffects[CEffectType::AmountIDs];

	std::function<void(CLifeObject &)>  m_functions_for_bonuses[CBonusesType::AmountIDs];

	ManageCircle						m_manageCirlce;
	// /\ 
private:
	cocos2d::Vec2			GetMiddleWindow() const;
	CLifeObject&			GetPlayer() const;
	// CreateGameScene.cpp
	void					CreateCashes();// TODO : delete if not need
	void					CreateTypesLifeObjects();
	void					CreateTypeLifeObject(TypeLifeObject::ID id
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
												, CEffectType::ID idEffectDeath);

	void					CreateTypesShoots();
	void					CreateTypeShoot(CShootType::ID id
											, const std::string & textureName
											, const std::string & nameRectangle
											, CEffectType::ID idEffectDeath);

	void					CreateTypesWeapons();
	void					CreateTypeWeapon(CTypeWeapon::ID id
											, const int damage
											, const float timeReload
											, CShootType::ID idShooteType
											, const float velocity
											, const float distanse
											, const std::string & nameSounds
											, const std::string & nameSoundFeatures);

	void					CreateTypesBonuses();
	void					CreateTypeBonus(CBonusesType::ID id
											, const std::string & textureName
											, const std::string & nameRectangle
											, const std::string & nameSounds
											, const std::string & nameSoundFeatures);
	
	void					CreateTypesEffects();
	void					CreateTypeEffect(CEffectType::ID id
											, const std::string & textureName
											, const std::string & nameRectangle
											, const std::string & timeLive
											, const std::string & timeAnimation);

	void					CreateMenu();
	void					CreateMoveCircle();
	void					CreateListener();

	void					CreateCamera();
	void					CreateMap();
	void					CreateWalls();
	void					CreateLifeObjects();
	void					CreateBonuses();

	void					CreateContactListener();

	void					CreateEffect(CEffectType::ID id, cocos2d::Vec2 position);
	// CreateAnimations.cpp
	void					CreateAnimations();

	CollectionAnimations	CreateEffectAnimations(const std::string & nameFile
													, const cocos2d::Rect & rectangle
													, const float timeAnimation);
	CollectionAnimations	CreateMoveAnimations(const std::string & nameFile
												, const cocos2d::Rect & rectangle
												, const float timeAnimation);
	CollectionAnimations	CreateAttackAnimations(const std::string & nameFile
													, const cocos2d::Rect & rectangle
													, const float timeAnimation);

	cocos2d::Vector<cocos2d::SpriteFrame*>	GetAnimation(const std::vector<std::string>& names);
	void					AddAnimationFrame(cocos2d::Vec2 & shift, const cocos2d::Size & size, const int index, const float timeAnimation,
												CollectionAnimations & collection, const int amountShoots,
												const std::string & nameFile, const std::string & nameAnimation);

	//*/

	// ActionsBonuses.cpp
	void					CreateFunctionsForBonuses();

	void					ReplaceWeaponOnGrenadeGun(CLifeObject & object);
	void					ReplaceWeaponOnPlasmaGun(CLifeObject & object);
	void					GetMedPack(CLifeObject & object);
	// UpdateGameScene.cpp
	void					UpdateManageCircle();
	void					UpdateShoots(float dt);
	void					UpdateBonuses();

	void					UpdateCamera(float dt);
	cocos2d::Camera &		GetCamera();
	void					ResetCamera();

	void					UpdateLifeObjects(float dt);
	void					CheckHealthLifeObjects();

	// UpdateEffects.cpp
	void					UpdateEffects(float dt);
	void					CheckStateEffects();

	// UpdateObjects.cpp
	void					SearchEnemy();// TODO : redefine later
	void					DefineDirectionToEnemyForObject(CLifeObject * object,
															const cocos2d::Vec2 & positionEnemy);
	void					DefineNeedAttackEnemy(CLifeObject * object,
															const cocos2d::Vec2 & positionEnemy);

	cocos2d::Vec2					GetTileCoordinateForPosition(cocos2d::Vec2 position);
	void					CheckCollisionPlayer(cocos2d::Vec2 position);


	bool					CheckVictoryCondition();
	bool					CheckDefeatCondition(size_t index);

	TypeLifeObject::ID		GetIdTypeLifeObject(const std::string & name);
	CBonusesType::ID		GetIdTypeBonuses(const std::string & name);

	// SoundsEngine.cpp
	void					CreateSounds();

	// ReadJson.cpp
	void					ReadTexturePaths(const std::string & jsonFileName);
	void					ReadRectangles(const std::string & jsonFileName);
	void					ReadGameConstants(const std::string & jsonFileName);
	void					ReadTimeLiveEffects(const std::string & jsonFileName);
	void					ReadTimeAnimations(const std::string & jsonFileName);
	void					ReadSoundsPath(const std::string & jsonFileName);

	void					WriteContent(std::ifstream & inputFile, std::string & content);

public:
		MapInt					m_gameIntConstats;
		MapFloat				m_gameFloatConstats;
		MapFloat				m_timeLiveEffects;
		MapFloat				m_timeAnimations;
		MapSoundsFeatures		m_soundsFeatures;
public:
		// SoundsEngine.cpp

		void					PlayRandomSound(const std::vector<std::string> & path
												, const SSoundFeatures & features);

private:
	cocos2d::PhysicsWorld*	m_World;
	cocos2d::CCTMXTiledMap* m_tileMap;
	cocos2d::CCTMXLayer*	m_collisionLayer;

	std::vector<std::shared_ptr<cocos2d::Sprite>> m_spriteCashe;
	std::vector<cocos2d::Animate*> m_pAnimates;


	// Data from json
	MapPath					m_texturePaths;
	MapPaths				m_soundsPaths;
	MapRect					m_rectanglePaths;
	/////////////////

	size_t					m_id_player = 0;
	size_t					m_amountMonsters = 10;

	cocos2d::Camera*		m_camera;

	bool					m_isTouching = false;
	cocos2d::Vec2			m_touchPosition = cocos2d::Vec2(0.f, 0.f);
};
