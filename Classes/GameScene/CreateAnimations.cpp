#include "CreateAnimations.h"

using namespace cocos2d;
using namespace std;

void GameScreen::CreateAnimations()
{

}
///*

CollectionAnimations GameScreen::CreateEffectAnimations(const string & nameFile
														, const Rect & rectangle
														, const float timeAnimation)
{
	CollectionAnimations effectAnimations;

	Rect frameAnimation = rectangle;
	Vec2 shift = Vec2::ZERO;
	Size size = frameAnimation.size;

	for (size_t indexAnimation = 0; indexAnimation < m_gameIntConstats["AMOUNT_EFFECT_ANIMATIONS"]; indexAnimation++)
	{
		AddAnimationFrame(shift, size, indexAnimation, timeAnimation,
			effectAnimations, m_gameIntConstats["AMOUNT_FRAMES_FOR_EFFECT"],
			nameFile, "Effect");

		shift.x += size.width;
		shift.y = 0.f;
	}

	return effectAnimations;
}

CollectionAnimations GameScreen::CreateMoveAnimations(const string & nameFile
													, const Rect & rectangle
													, const float timeAnimation)
{
	CollectionAnimations moveAnimations;

	Rect frameAnimation = rectangle;
	Vec2 shift = Vec2::ZERO;
	Size size = frameAnimation.size;

	for (size_t indexAnimation = 0; indexAnimation < m_gameIntConstats["AMOUNT_MOVE_ANIMATIONS"]; indexAnimation++)
	{
		AddAnimationFrame(shift, size, indexAnimation, timeAnimation,
						moveAnimations, m_gameIntConstats["AMOUNT_FRAMES_FOR_MOVE"],
						nameFile, "move");

		shift.x += size.width;
		shift.y = 0.f;
	}

	return moveAnimations;
}

CollectionAnimations GameScreen::CreateAttackAnimations(const string & nameFile
														, const Rect & rectangle
														, const float timeAnimation)
{
	CollectionAnimations attackAnimations;

	Rect frameAnimation = rectangle;
	Size size = frameAnimation.size;
	Vec2 startShift = Vec2(0.f, static_cast<float>(m_gameIntConstats["AMOUNT_FRAMES_FOR_MOVE"]) 
							* (size.height + GameSceneRecourses::SHIFT_FROM_FRAME));
	Vec2 shift = startShift;

	for (size_t indexAnimation = 0; indexAnimation < m_gameIntConstats["AMOUNT_MOVE_ANIMATIONS"]; indexAnimation++)
	{
		AddAnimationFrame(shift, size, indexAnimation, timeAnimation,
			attackAnimations, m_gameIntConstats["AMOUNT_FRAMES_FOR_ATTACK"],
			nameFile, "attack");

		shift.x += size.width;
		shift.y = startShift.y;
	}

	return attackAnimations;
}

Vector<SpriteFrame*>  GameScreen::GetAnimation(const std::vector<std::string> & names)
{
	auto spriteFrameCashe = SpriteFrameCache::getInstance();

	Vector<SpriteFrame*> result;
	for (const auto & name : names)
	{
		result.pushBack(spriteFrameCashe->getSpriteFrameByName(name));
	}

	return result;
}

void GameScreen::AddAnimationFrame(Vec2 & shift, const Size & size, const int index, const float timeAnimation,
									CollectionAnimations & collection, const int amountShoots,
									const string & nameFile, const string & nameAnimation)
{
	auto animationCashe = AnimationCache::getInstance();
	auto spriteFrameCashe = SpriteFrameCache::getInstance();

	Vector<SpriteFrame*> frames;

	std::vector<std::string> namesFrames;

	for (size_t i = 0; i < amountShoots; i++)
	{
		auto frame = SpriteFrame::create(nameFile, Rect(shift, size));

		namesFrames.push_back(nameFile 
							+ nameAnimation
							+ static_cast<char>(static_cast<int>(shift.x +'0'))
							+ '_' 
							+ static_cast<char>(static_cast<int>(shift.y +'0')));

		spriteFrameCashe->addSpriteFrame(frame, namesFrames[i]);
		frames.pushBack(frame);

		shift.y += size.height + GameSceneRecourses::SHIFT_FROM_FRAME;
	}

	Animation* animation = Animation::createWithSpriteFrames(GetAnimation(namesFrames),
																timeAnimation / namesFrames.size());

	std::string nameAnimationInCashe = nameFile + nameAnimation + static_cast<char>(index + '0');//std::to_string
	animationCashe->addAnimation(animation, nameAnimationInCashe);
	//make_shared<Animate>()
	//m_animateCashe.push_back(make_shared<Animate>(Animate::create(animationCashe->getAnimation(nameAnimation))));

	collection.pushBack(animationCashe->getAnimation(nameAnimationInCashe));
}
//*/