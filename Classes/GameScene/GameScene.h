#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "Config.h"
namespace GameSceneTexture
{
	static const std::string PATH_TEXTURE = "GameScene\\";
	static const std::string BACKGROUND = PATH_TEXTURE + "Background.png";

	static const std::string MARINE = PATH_TEXTURE + "Marine.png";// TODO : replace

}

namespace MoveCircleParametrs
{
	static const std::string PATH_TEXTURE = "GameScene\\";

	static const std::string MOVE_CIRCLE = PATH_TEXTURE + "MoveCircle.png";
	static const float RADIUS_MOVE_CIRCLE = 30.f;
	static const float RADIUS_ATTACK_CIRCLE = 20.f;
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
	void CreateMenu();
	void CreateMoveCircle();
	void CreateListener();
	void CreatePlayer();


};

#endif // __GAME_SCENE_H__