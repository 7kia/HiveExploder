#include "HaveDeathEffect.h"

void CHaveDeathEffect::SetIdDeathEffect(CEffectType::ID id)
{
	m_idDeathEffect = id;
}

CEffectType::ID CHaveDeathEffect::GetIdDeathEffect() const
{
	return m_idDeathEffect;
}
