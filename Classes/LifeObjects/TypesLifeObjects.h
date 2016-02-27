#ifndef TYPESLIFEOBJECTS_H
#define TYPESLIFEOBJECTS_H

#pragma once

#include "../Visual/Visual.h"
#include "FeaturesLifeObject.h"

namespace TypePlayer// TODO : redesign
{
	cocos2d::Rect textureRectangle(0, 0, 40, 40);
	static const std::string TEXTURE_NAME = "Marine.png";
}

namespace TypeZergling// TODO : redesign
{
	cocos2d::Rect textureRectangle(0, 0, 40, 40);
	static const std::string TEXTURE_NAME = "Zergling.png";
}

namespace TypeHydralisk// TODO : redesign
{
	cocos2d::Rect textureRectangle(0, 0, 40, 40);
	static const std::string TEXTURE_NAME = "Hydralisk.png";
}

class TypeLifeObject
{
public:
	enum ID
	{
		Player = 0		,
		Zergling		,
		Hydralisk		,
		AmountIDs
	};

	// Texture in TextureHolder
	void SetTexture(cocos2d::Texture2D* setTexture);
	cocos2d::Texture2D* GetTexture() const;

	void SetTextureRect(cocos2d::Rect setRectangle);
	cocos2d::Rect GetRectangle() const;
	// TODO : there not enough functional
private:
	cocos2d::Texture2D* texture;
	cocos2d::Rect rectangle;
};

#endif