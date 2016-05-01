#include "Effect.h"

using namespace cocos2d;

CEffect::CEffect() : CEntity()
{
	this->SetIdClass(idClass::Effect);
	CEntity::init();
}

CEffect::~CEffect()
{
}

void CEffect::SetType(const CEffectType & defineType)
{
	m_type.reset(&defineType);// = &;

	setTexture(m_type->GetTexture());
	setTextureRect(m_type->GetTextureRectangle());

	//setAnchorPoint(m_type->GetTextureRectangle().size / 2.f);

	Animate* newAnimate = Animate::create(m_type->GetAnimations().at(0));
	runAction(newAnimate);
}

const CEffectType& CEffect::GetType()
{
	return *m_type;
}

void CEffect::update(float dt)
{
	if (m_timeLife < m_type->GetLifeTime())
	{
		m_timeLife += dt;
	}
	else
	{
		m_state = State::Death;
	}
}

void CEffect::SetState(CEffect::State state)
{
	m_state = state;
}

CEffect::State CEffect::GetState() const
{
	return m_state;
}
