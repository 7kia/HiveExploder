#pragma once

#include "../Effect/Effect.h"

class CHaveDeathEffect
{
public:
	void							SetIdDeathEffect(CEffectType::ID id);
	CEffectType::ID					GetIdDeathEffect() const;
private:
	CEffectType::ID					m_idDeathEffect = CEffectType::ID::None;
};