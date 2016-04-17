#include "HealthBar.h"
#include "../LifeObjects/LifeObjects.h"

using namespace cocos2d;

CBar::CBar() : CEntity()
{
	this->SetIdClass(idClass::HealthBar);
	CEntity::init();
}

CBar& CBar::operator=(const CBar& right) {
	//проверка на самоприсваивание
	if (this == &right) {
		return *this;
	}
	this->m_direction = right.m_direction;
	this->m_master = right.m_master;

	this->setContentSize(right.getContentSize());
	this->setTexture(right.getTexture());
	this->setTextureRect(right.getTextureRect());

	this->m_velocity = right.m_velocity;

	return *this;
}

CBar::CBar(Texture2D *texture, const Rect & rectangle) : CEntity()
{
	this->SetIdClass(idClass::HealthBar);
	CEntity::init();

	setTexture(texture);
	setTextureRect(Rect(0.f, rectangle.size.height  / 2.f,
								rectangle.size.width, rectangle.size.height));
	setContentSize(rectangle.size);
	setAnchorPoint(Vec2(rectangle.size.width / 2.f, -rectangle.size.height));
}

CBar::~CBar()
{
}

void CBar::cleanup()
{
}

void CBar::update(float dt)
{
	SetTextureRect();
	UpdatePosition();
}

void CBar::SetMaster(CLifeObject & master)
{
	m_master = &master;
}

CLifeObject & CBar::GetMaster()
{
	return *m_master;
}

void CBar::SetTextureRect()
{
	float proportion = static_cast<float>(m_master->GetHealth()) / static_cast<float>(m_master->GetMaxHealth());

	if (proportion > 1.f)
	{
		proportion = 1.f;
	}
	else if(proportion < 1.f)
	{
		proportion = proportion;
	}

	const Size size = getContentSize();
	float width = size.width * proportion;
	setTextureRect(Rect(0.f, size.height / 2.f,
						width, size.height));

}

void CBar::UpdatePosition()
{
	const Vec2 positionMaster = GetMaster().getPosition();
	Vec2 shift = GetMaster().getAnchorPoint();

	setPosition(positionMaster);
}
