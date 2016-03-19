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
			m_shoots[index]->removeFromParent();

			m_shoots.erase(m_shoots.begin() + index);
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