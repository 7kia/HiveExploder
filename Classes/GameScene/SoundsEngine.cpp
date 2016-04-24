#include "GameScene.h"

#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

using namespace cocos2d;
using namespace std;
using namespace CocosDenshion; 
using namespace cocostudio::timeline;

void GameScreen::CreateSounds()
{
	auto audio = SimpleAudioEngine::getInstance();
	//SimpleAudioEngine::getInstance()->playBackgroundMusic("Academeg.mp3", true);
	for (size_t index = 0; Sounds::AMOUNT_VARIATIONS; index++)
	{
		audio->preloadEffect(Sounds::MARINE_SHOOT[index].c_str());
		audio->preloadEffect(Sounds::MARINE_DEATH[index].c_str());


	}
}

void GameScreen::PlayRandomSound(const std::string * path)
{
	auto audio = SimpleAudioEngine::getInstance()->getInstance();

	int index = rand() % Sounds::AMOUNT_VARIATIONS;
	
	//if(audio->getInstance())
	audio->playEffect(path[index].c_str());
}
