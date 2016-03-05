#pragma once

// TODO : delete if will not need
//#include <SFML/Graphics/RenderWindow.hpp>
//#include <SFML/Graphics.hpp>
#include "cocos2d.h"
//#include "../StructGame/ResourceIdentifiers.h"

class CVisual : public cocos2d::Sprite
{
public:
	void			Move(cocos2d::Vec2 shiftVector);
	
<<<<<<< dev

	std::shared_ptr<cocos2d::Sprite>  GetSprite();
	void SetSprite(std::shared_ptr<cocos2d::Sprite>  setSprite);

public:// TODO : will do private
	std::shared_ptr<cocos2d::Sprite>  sprite;
=======
//public:// TODO : will do private
	//cocos2d::Sprite* sprite;
>>>>>>> local
};
