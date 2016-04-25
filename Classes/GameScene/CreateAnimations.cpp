#include "GameScene.h"

using namespace cocos2d;
using namespace std;

void GameScreen::CreateAnimations()
{

}
///*

// TODO : NOT WORK!!!
CollectionAnimations GameScreen::CreateMoveAnimations(const string & nameFile, const Rect & rectangle)
{
	CollectionAnimations moveAnimations;

	Rect frameAnimation = rectangle;
	Vec2 shift = Vec2::ZERO;
	Size size = frameAnimation.size;

	for (size_t indexAnimation = 0; indexAnimation < m_gameIntConstats["AMOUNT_MOVE_ANIMATIONS"]; indexAnimation++)
	{
		AddAnimationFrame(shift, size, indexAnimation,
						moveAnimations, nameFile);

		shift.x += size.width;
		shift.y = 0.f;
	}

	return moveAnimations;
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

void GameScreen::AddAnimationFrame(Vec2 & shift, const Size & size, const int index,
									CollectionAnimations & collection, const string & nameFile)
{
	auto animationCashe = AnimationCache::getInstance();
	auto spriteFrameCashe = SpriteFrameCache::getInstance();

	Vector<SpriteFrame*> frames(m_gameFloatConstats["AMOUNT_FRAMES_FOR_MOVE"]);

	std::vector<std::string> namesFrames;

	for (size_t i = 0; i < m_gameFloatConstats["AMOUNT_FRAMES_FOR_MOVE"]; i++)
	{
		auto frame = SpriteFrame::create(nameFile, Rect(shift, size));

		namesFrames.push_back(nameFile 
							+ "move" 
							+ to_string(static_cast<int>(shift.x))
							+ '_' 
							+ to_string(static_cast<int>(shift.y)));

		spriteFrameCashe->addSpriteFrame(frame, namesFrames[i]);
		frames.pushBack(frame);

		shift.y += size.height + GameSceneRecourses::SHIFT_FROM_FRAME;
	}

	Animation* animation = Animation::createWithSpriteFrames(GetAnimation(namesFrames),
																GameSceneRecourses::TIME_MOVE_ANIMATION_FRAME);

	std::string nameAnimation = nameFile + "move" + to_string(index);
	animationCashe->addAnimation(animation, nameAnimation);
	//make_shared<Animate>()
	//m_animateCashe.push_back(make_shared<Animate>(Animate::create(animationCashe->getAnimation(nameAnimation))));

	collection.pushBack(animationCashe->getAnimation(nameAnimation));
}
//*/