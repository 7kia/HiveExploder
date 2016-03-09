#pragma once
#include "Collision.h"
//#include "../Visual/Visual.h"
#include "Entity.h"
#include "FeaturesLifeObject.h"

/*

*/


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
	void					SetTexture(cocos2d::Texture2D* setTexture);
	cocos2d::Texture2D*		GetTexture() const;

	void					SetTextureRect(cocos2d::Rect setRectangle);
	cocos2d::Rect			GetRectangle() const;

	void					SetVelocity(float setVelocity);
	float					GetVelocity() const;

	void					SetHealth(int value);
	int						GetHealth();
	// TODO : there not enough functional
private:
	cocos2d::Texture2D*		texture;
	cocos2d::Rect			rectangle;
	float					velocity;
	CDynamicFeature			health;
};
