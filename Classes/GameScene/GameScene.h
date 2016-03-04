#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "Config.h"
#include "ManageCircle.h"
#include "../LifeObjects/LifeObjects.h"
#include "../Shoots/shoot.h"

namespace GameSceneTexture// TODO : redesign
{
	static const std::string PATH_TEXTURE = "GameScene\\";
	static const std::string BACKGROUND = PATH_TEXTURE + "Background.png";

	static const std::string MANAGE_CIRCLE = PATH_TEXTURE + "MoveCircle.png";

	//namespace TypePlayer// TODO : redesign
	//{
	static const cocos2d::Rect MARINE_RECT(0, 0, 40, 40);
	static const std::string MARINE = "Marine.png";

	static const cocos2d::Rect MARINE_SHOOT_RECT(0, 0, 8, 49);
	static const std::string MARINE_SHOOT = "Marine_gun_bullet.png";
	//


	//}

	//namespace TypeZergling// TODO : redesign
	//{
		static const cocos2d::Rect ZERGLING_RECT(0, 0, 40, 40);
		static const std::string ZERGLING = "Zergling.png";
	//}

	//namespace TypeHydralisk// TODO : redesign
	//{
		static const cocos2d::Rect HYDRALISK_RECT(0, 0, 40, 40);
		static const std::string HYDRALISK = "Hydralisk.png";
	//}

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
    
    void					update(float dt);
    
	bool					onTouchBegan(cocos2d::Touch *touch, cocos2d::Event * event);
	void					onTouchMoved(cocos2d::Touch *touch, cocos2d::Event * event);
	void					onTouchEnded(cocos2d::Touch *touch, cocos2d::Event * event);
	void					onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event * event);

	void					AddShoot(const CShoot & addShoot);

	/////// XXXXXXXXXXXx
	void					SetPhysicsWorld(cocos2d::PhysicsWorld* world)
	{
		m_World = world; m_World->setGravity(cocos2d::Vect(0, 0)); 
	}
	bool					onContactBegin(cocos2d::PhysicsContact& contact);
	////// XXXXXXXXXXXX
	// \/
	// TODO : see need there private
	//
public:
	std::vector<CLifeObject>	lifeObjects;
	std::vector<CShoot>			shoots;

	TypeLifeObject			typesLifeObjects[TypeLifeObject::AmountIDs];
	TypeShoot				typesShoots[TypeShoot::AmountIDs];


	ManageCircle			manageCirlce;
	// /\ 
private:
	// CreateGameScene.cpp
	void					CreateCashes();
	void					CreateTypesLifeObjects();
	void					CreateTypesShoots();

	void					CreateMenu();
	void					CreateMoveCircle();
	void					CreateListener();

	void					CreatePlayer();
	void					CreateEnemys();
	void					CreateContactListener();// XXXXXX
	// UpdateGameScene.cpp
	void					UpdateManageCircle();
	void					UpdateShoots(float dt);
private:
	cocos2d::PhysicsWorld*	m_World;

	size_t					ID_PLAYER = 0;

	bool					isTouching = false;
	cocos2d::Vec2			touchPosition = cocos2d::Vec2(0.f, 0.f);

};

#endif // __GAME_SCENE_H__
