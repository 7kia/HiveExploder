#include "GameScene.h"

using namespace cocos2d;

void GameScreen::UpdateShoots(float dt)
{
	size_t index = 0;
	while (index < m_shoots.size())
	{
		m_shoots[index]->update(dt);

		if (m_shoots[index]->GetVelocity() < ABOUT_ZERO_VALUE_SPEED_BULLET)
		{

			CreateEffect(m_shoots[index]->GetType().GetIdDeathEffect(), m_shoots[index]->getPosition());

			m_shoots[index]->removeFromParent();

			m_shoots.erase(m_shoots.begin() + index);
		}
		else
		{
			index++;
		}
	}
}

void GameScreen::UpdateBonuses()
{
	size_t index = 0;
	while (index < m_bonuses.size())
	{
		if (m_bonuses[index]->GetState())
		{
			const CBonusesType *type = &m_bonuses[index]->GetType();
			PlayRandomSound(type->GetSounds("DEATH"), type->GetSoundsFeatures());

			m_bonuses[index]->removeFromParent();

			m_bonuses.erase(m_bonuses.begin() + index);
		}
		else
		{
			index++;
		}
	}
}


void GameScreen::AddShoot(CShoot &addShoot)
{
	m_shoots.push_back(&addShoot);
}