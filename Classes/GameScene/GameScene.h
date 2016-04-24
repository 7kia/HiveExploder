#pragma once

#include "Config.h"
#include "ManageCircle.h"
#include "../LifeObjects/LifeObjects.h"
#include "../Shoots/shoot.h"
#include "../Entity/Weapon.h"
#include "../Bonuses/Bonuses.h"
#include "../HealthBar/HealthBar.h"
 
#include "SimpleAudioEngine.h"

namespace Sounds// TODO : redesign
{
	static const std::string PATH = "GameScene/Sounds/";

	static const int AMOUNT_VARIATIONS = 7;
	static const std::string MARINE_SHOOT[AMOUNT_VARIATIONS] = { 
		PATH + "Marine_AttackLaunch0.wav",
		PATH + "Marine_AttackLaunch1.wav",
		PATH + "Marine_AttackLaunch2.wav",
		PATH + "Marine_AttackLaunch3.wav",
		PATH + "Marine_AttackLaunch4.wav",
		PATH + "Marine_AttackLaunch5.wav",
		PATH + "Marine_AttackLaunch6.wav"
	};
	static const std::string MARINE_DEATH[AMOUNT_VARIATIONS] = {
		PATH + "Marine_Death01.wav",
		PATH + "Marine_Death02.wav",
		PATH + "Marine_Death03.wav",
		PATH + "Marine_Death04.wav",
		PATH + "Marine_Death05.wav",
		PATH + "Marine_Death06.wav",
		PATH + "Marine_Death07.wav"
	};

}

namespace GameSceneRecourses// TODO : redesign
{
	static const std::string PATH = "GameScene/";

	static const std::string BACKGROUND = PATH + "Background.png";

	static const std::string MAP = PATH + "Map/map.tmx";
	static const int kTagTileMap = 2;

	static const int AMOUNT_FRAMES_FOR_MOVE = 5;
	static const int AMOUNT_MOVE_ANIMATIONS = 8;
	static const float SHIFT_FROM_FRAME = 1.f;
	static const float TIME_MOVE_ANIMATION_FRAME = 0.2f;

	static const cocos2d::Rect BONUS_RECT(0, 0, 100, 100);
	static const std::string BONUS_MED_PACK = PATH + "MedPack.png";
	static const int MED_PACK_ADD_HEALTH = 100;

	static const std::string BONUS_GRENADE_GUN = PATH + "GrenadeGun.png";
	static const std::string BONUS_PLASMA_GUN = PATH + "PlasmaGun.png";

	static const cocos2d::Rect GRENADE_RECT(0, 0, 30, 30);
	static const std::string GRENADE = PATH + "Grenade.png";

	static const cocos2d::Rect PLASMA_SHOOT_RECT(0, 0, 35, 45);
	static const std::string PLASMA_SHOOT = PATH + "PlasmaShoot.png";


	static const cocos2d::Rect HEALTH_BAR_RECT(0, 0, 50, 5);
	static const std::string HEALTH_BAR = PATH + "HealthBar.png";


	static const std::string MANAGE_CIRCLE = PATH + "MoveCircle.png";

	//namespace TypePlayer// TODO : redesign
	//{
	static const cocos2d::Rect MARINE_RECT(0, 0, 60, 60);
	static const std::string MARINE = PATH + "Marine.png";

	static const cocos2d::Rect MARINE_SHOOT_RECT(0, 0, 8, 49);
	static const std::string MARINE_SHOOT = PATH + "Marine_gun_bullet.png";

	static const cocos2d::Rect MELEE_SHOOT_RECT(0, 0, 10, 10);
	static const std::string MELEE_SHOOT = PATH + "Melee.png";


	//


	//}

	//namespace TypeZergling// TODO : redesign
	//{
		static const cocos2d::Rect ZERGLING_RECT(0, 0, 60, 60);
		static const std::string ZERGLING = PATH + "Zergling.png";
	//}

	//namespace TypeHydralisk// TODO : redesign
	//{
		static const cocos2d::Rect HYDRALISK_RECT(0, 0, 80, 80);
		static const std::string HYDRALISK = PATH + "Hydralisk.png";
	//}
		static const cocos2d::Rect HYDRALISK_SHOOT_RECT(0, 0, 8, 32);
		static const std::string HYDRALISK_SHOOT = PATH + "Hydralisk_shoot.png";


		static const int levelInterface = -1;
		static const int levelObjects = -2;
		static const int levelMap = -3;
}

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

	TypeLifeObject						m_typesLifeObjects[TypeLifeObject::AmountIDs];
	CTypeWeapon							m_typesWeapons[CTypeWeapon::AmountIDs];
	CShootType							m_typesShoots[CShootType::AmountIDs];
	CBonusesType						m_typeBonuses[CBonusesType::AmountIDs];

	std::function<void(CLifeObject &)>  m_functions_for_bonuses[CBonusesType::AmountIDs];

	ManageCircle						m_manageCirlce;
	// /\ 
private:
	cocos2d::Vec2			GetMiddleWindow() const;
	CLifeObject&			GetPlayer() const;
	void					UpdateTouchPosition(cocos2d::Touch *touch);
	// CreateGameScene.cpp
	void					CreateCashes();// TODO : delete if not need
	void					CreateTypesLifeObjects();
	void					CreateTypesShoots();
	void					CreateTypesWeapons();
	void					CreateTypesBonuses();

	void					CreateMenu();
	void					CreateMoveCircle();
	void					CreateListener();

	void					CreateCamera();
	void					CreateMap();
	void					CreateWalls();
	void					CreateLifeObjects();
	void					CreateBonuses();

	void					CreateContactListener();
	// CreateAnimations.cpp
	void					CreateAnimations();
	CollectionAnimations	CreateMoveAnimations(const std::string & nameFile, const cocos2d::Rect & rectangle);
	cocos2d::Vector<cocos2d::SpriteFrame*>	GetAnimation(const std::vector<std::string>& names);
	void					AddAnimationFrame(cocos2d::Vec2 & shift, const cocos2d::Size & size, const int index,
												CollectionAnimations & collection, const std::string & nameFile);

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
	void					PlayRandomSound(const std::string * path);
private:
	cocos2d::PhysicsWorld*	m_World;
	cocos2d::CCTMXTiledMap* m_tileMap;
	cocos2d::CCTMXLayer*	m_collisionLayer;

	std::vector<std::shared_ptr<cocos2d::Sprite>> m_spriteCashe;
	std::vector<cocos2d::Animate*> m_pAnimates;


	size_t					m_id_player = 0;
	size_t					m_amountMonsters = 10;

	cocos2d::Camera*		m_camera;

	bool					m_isTouching = false;
	cocos2d::Vec2			m_touchPosition = cocos2d::Vec2(0.f, 0.f);
};
