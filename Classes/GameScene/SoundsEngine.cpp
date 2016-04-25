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
	for (const auto & element : m_soundsPaths)
	{
		for (size_t index = 0; element.second.size(); index++)
		{
			audio->preloadEffect(element.second[index].c_str());
		}
	}
}

void GameScreen::PlayRandomSound(const std::vector<std::string> & path)
{
	auto audio = SimpleAudioEngine::getInstance()->getInstance();

	int index = rand() % path.size();
	
	//if(audio->getInstance())
	audio->playEffect(path[index].c_str(), false);
}
