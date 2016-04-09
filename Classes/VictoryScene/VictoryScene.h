#pragma once

#include "cocos2d.h"

namespace VictoryTexture
{
	static const std::string PATH_TEXTURE = "VictoryScreen/";

	static const std::string BACKGROUND = PATH_TEXTURE + "Background.png";
}

class Victory : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene*	createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool			init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(Victory);
      
    void					GoToMainMenuScene(Ref *pSender);
    
	void					CreateMenu();
	void					CreateBackground();

};
