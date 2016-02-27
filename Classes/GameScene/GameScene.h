#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "Config.h"
#include "ManageCircle.h"
#include "../LifeObjects/LifeObjects.h"

namespace GameSceneTexture// TODO : redesign
{
	static const std::string PATH_TEXTURE = "GameScene\\";
	static const std::string BACKGROUND = PATH_TEXTURE + "Background.png";

	static const std::string MANAGE_CIRCLE = PATH_TEXTURE + "MoveCircle.png";

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
    
    void GoToPauseScene(Ref *pSender);
    void GoToGameOverScene(Ref *pSender);
	void GoToVictoryScene(cocos2d::Ref * pSender);
    
    void update(float dt);
    
	bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event * event);
	void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event * event);
	void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event * event);
	void onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event * event);

	bool isTouching = false;
	cocos2d::Vec2 touchPosition = cocos2d::Vec2(0.f, 0.f);
    //std::vector<cocos2d::Sprite *> asteroids;
    
    cocos2d::Sprite *playerSprite;
private:
	// CreateGameScene.cpp
	void CreateTypesLifeObjects();
	void CreateMenu();
	void CreateMoveCircle();
	void CreateListener();
	void CreatePlayer();
	// UpdateGameScene.cpp
	void UpdateManageCircle();
private:
	ManageCircle manageCirlce;
	TypeLifeObject typesLifeObjects[TypeLifeObject::AmountIDs];

};

#endif // __GAME_SCENE_H__
