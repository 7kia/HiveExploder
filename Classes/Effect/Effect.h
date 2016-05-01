#pragma once

#include "TypeEffect.h"

class CEffect : public CEntity
{
public:
	CEffect();
	//CShoot(const CShoot& copy);
	virtual ~CEffect() override;

	enum class State
	{
			Live = 0
		,	Death
	};

public:

	static CEffect* create();

	void								SetType(const CEffectType &defineType);
	const CEffectType&					GetType();

	void								update(float dt) override;

	void								SetState(State state);
	State								GetState() const;
private:
	std::shared_ptr<const CEffectType>	m_type;

	float								m_timeLife = 0.f;
	State								m_state = State::Live;
};