#pragma once
#include "Entity.h"
#include "Collision.h"
#include "Features.h"

class TypeLifeObject
{
public:
	enum ID
	{
		None = -1		,
		Player			,
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

	void					SetDamage(int value);
	int						GetDamage();

	void					SetId(ID id);
	ID						GetId();
	// TODO : there not enough functional
private:
	cocos2d::Texture2D*		m_texture;
	cocos2d::Rect			m_rectangle;
	float					m_velocity;

	CDynamicFeature			m_health;
	CDynamicFeature			m_damage;

	ID						m_id = ID::None;
};
