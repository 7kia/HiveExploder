#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"

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
    
    cocos2d::Sprite *backgroundSpriteArray[2];
    cocos2d::Sprite *playerSprite;
};

#endif // __GAME_SCENE_H__
