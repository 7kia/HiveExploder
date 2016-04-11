#pragma once

#include "Config.h"
#include "ManageCircle.h"
#include "../LifeObjects/LifeObjects.h"
#include "../Shoots/shoot.h"
#include "../Entity/Weapon.h"
 

namespace GameSceneRecourses// TODO : redesign
{
	static const std::string PATH = "GameScene/";
	static const std::string BACKGROUND = PATH + "Background.png";

	static const std::string MAP = PATH + "tmx/map2.tmx";
	static const int kTagTileMap = 10;

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

	TypeLifeObject						m_typesLifeObjects[TypeLifeObject::AmountIDs];
	CTypeWeapon							m_typesWeapons[CTypeWeapon::AmountIDs];
	CShootType							m_typesShoots[CShootType::AmountIDs];


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

	void					CreateMenu();
	void					CreateMoveCircle();
	void					CreateListener();

	void					CreateCamera();
	void					CreateMap();
	void					CreateWalls();
	void					CreateLifeObjects();
	void					CreateContactListener();
	// UpdateGameScene.cpp
	void					UpdateManageCircle();
	void					UpdateShoots(float dt);
	void					UpdateCamera(float dt);
	void					UpdateLifeObjects(float dt);
	void					CheckHealthLifeObjects();
	void					SearchEnemy();// TODO : redefine later

	bool					CheckVictoryCondition();
	bool					CheckDefeatCondition(size_t index);

	TypeLifeObject::ID		GetIdTypeLifeObject(const std::string & name);
private:
	cocos2d::PhysicsWorld*	m_World;
	cocos2d::CCTMXTiledMap* m_tileMap;
	size_t					m_id_player = 0;
	size_t					m_amountMonsters = 10;

	cocos2d::Camera*		m_camera;

	bool					m_isTouching = false;
	cocos2d::Vec2			m_touchPosition = cocos2d::Vec2(0.f, 0.f);
};
