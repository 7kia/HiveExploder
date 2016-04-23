#include "GameScene.h"

using namespace cocos2d;
using namespace std;

void GameScreen::CreateAnimations()
{

}


CollectionAnimations GameScreen::CreateMoveAnimations(const string & nameFile, const Rect & rectangle)
{
	CollectionAnimations moveAnimations;

	Rect frameAnimation = rectangle;
	Vec2 shift = Vec2::ZERO;
	Size size = frameAnimation.size;

	for (size_t indexAnimation = 0; indexAnimation < GameSceneRecourses::AMOUNT_MOVE_ANIMATIONS; indexAnimation++)
	{
		AddAnimationFrame(shift, size, moveAnimations, nameFile);

		shift.x += size.width;
		shift.y = 0.f;
	}

	return moveAnimations;
}

void GameScreen::AddAnimationFrame(Vec2 & shift, const Size & size,
									CollectionAnimations & collection, const string & nameFile)
{
	Vector<SpriteFrame*> frames(GameSceneRecourses::AMOUNT_FRAMES_FOR_MOVE);

	for (int i = 0; i < GameSceneRecourses::AMOUNT_FRAMES_FOR_MOVE; i++)
	{
		auto frame = SpriteFrame::create(nameFile, Rect(shift, size));
		frames.pushBack(frame);

		shift.y += size.height + GameSceneRecourses::SHIFT_FROM_FRAME;
	}

	Animation* animation = Animation::createWithSpriteFrames(frames, GameSceneRecourses::TIME_MOVE_ANIMATION_FRAME);
	//make_shared<Animate>()
	collection.push_back(Animate::create(animation));
}