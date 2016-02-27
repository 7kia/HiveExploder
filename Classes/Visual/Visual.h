#ifndef VISUAL_H
#define VISUAL_H

#pragma once

// TODO : delete if will not need
//#include <SFML/Graphics/RenderWindow.hpp>
//#include <SFML/Graphics.hpp>
#include "cocos2d.h"
//#include "../StructGame/ResourceIdentifiers.h"

class CVisual
{
public:
	void SetTexture(cocos2d::Texture2D* texture);
	void SetTextureRect(cocos2d::Rect rectangle);
	cocos2d::Rect GetGlobalBounds() const;

	void SetOrigin(cocos2d::Vec2 setOrigin);

	// For compute middle sprite
	//const cocos2d::Vec2 computeMiddle(cocos2d::Rect rectangle);

	enum class IDCoordinate
	{
		X,
		Y
	};
	void SetPosition(cocos2d::Vec2 pos);
	float GetPosition(IDCoordinate id) const;
	cocos2d::Vec2 GetPosition() const;
	void Move(cocos2d::Vec2 shiftVector);

	//void draw(sf::RenderWindow &window);

private:
	cocos2d::Sprite* sprite;
};

#endif