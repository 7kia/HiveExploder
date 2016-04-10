#pragma once

#include "../Entity/Entity.h"
#include "../Entity/Collision.h"
#include "../Entity/Features.h"
#include "../Entity/Weapon.h"

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

	void					SetTexture(cocos2d::Texture2D* setTexture);
	cocos2d::Texture2D*		GetTexture() const;

	void					SetTextureRect(cocos2d::Rect setRectangle);
	cocos2d::Rect			GetRectangle() const;

	void					SetVelocity(float setVelocity);
	float					GetVelocity() const;

	void					SetHealth(int value);
	int						GetHealth();

	int						GetDamage();

	void					SetWeapon(const CTypeWeapon& weapon);
	const CTypeWeapon&		GetTypeWeapon() const;


	void					SetId(ID id);
	ID						GetId();
	// TODO : there not enough functional
private:
	cocos2d::Texture2D*		m_texture;
	cocos2d::Rect			m_rectangle;
	float					m_velocity;

	CDynamicFeature			m_health;
	const CTypeWeapon*		m_weapon;

	ID						m_id = ID::None;
};
