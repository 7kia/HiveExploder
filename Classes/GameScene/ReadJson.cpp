#include "ReadJson.h"

using namespace std;
using namespace cocos2d;
using namespace rapidjson;

void GameScreen::ReadTexturePaths(const string & jsonFileName)
{
	///*
		ifstream inputFile(jsonFileName);

	if (inputFile.is_open())
	{
		string content;
		WriteContent(inputFile, content);

		Document value;
		value.Parse(content.c_str());

		auto dictionaryPaths = value.MemberBegin();

		string path = dictionaryPaths->value.GetString();
		for (auto itr = ++dictionaryPaths; itr != value.MemberEnd(); ++itr)
		{
			m_texturePaths.emplace(itr->name.GetString(),
									path + itr->value.GetString());
		}

	}
	//*/

	/*
	string path = "iphone/GameScene/";

	m_texturePaths["MAP"] = path + "Map/map.tmx";
	m_texturePaths["BONUS_MED_PACK"] = path + "MedPack.png";//
	m_texturePaths["BONUS_GRENADE_GUN"] = path + "GrenadeGun.png";
	m_texturePaths["BONUS_PLASMA_GUN"] = path + "PlasmaGun.png";
	m_texturePaths["GRENADE"] = path + "Grenade.png";
	m_texturePaths["GRENADE_SHOOT_DEATH"] = path + "Grenade_shoot_Death.png";
	m_texturePaths["PLASMA_SHOOT"] = path + "PlasmaShoot.png";
	m_texturePaths["PLASMA_SHOOT_DEATH"] = path + "Plasma_shoot_Death.png";
	m_texturePaths["HEALTH_BAR"] = path + "HealthBar.png";
	m_texturePaths["MANAGE_CIRCLE"] = path + "MoveCircle.png";
	m_texturePaths["MARINE"] = path + "Marine.png";
	m_texturePaths["MARINE_DEATH"] = path + "marine_death.png";
	m_texturePaths["MARINE_SHOOT"] = path + "Marine_gun_bullet.png";
	m_texturePaths["MELEE_SHOOT"] = path + "Melee.png";
	m_texturePaths["ZERGLING"] = path + "Zergling.png";
	m_texturePaths["ZERGLING_DEATH"] = path + "Zergling_Death.png";
	m_texturePaths["HYDRALISK"] = path + "Hydralisk.png";
	m_texturePaths["HYDRALISK_DEATH"] = path + "Hydralisk_death.png";
	m_texturePaths["HYDRALISK_SHOOT"] = path + "Hydralisk_shoot.png";
	//*/
}

void GameScreen::ReadRectangles(const string & jsonFileName)
{
	///*
		ifstream inputFile(jsonFileName);

	if (inputFile.is_open())
	{
		string content;
		WriteContent(inputFile, content);

		Document value;
		value.Parse(content.c_str());

		auto dictionaryPaths = value.MemberBegin();

		Rect inputRectangles;

		for (auto itr = dictionaryPaths; itr != value.MemberEnd(); ++itr)
		{
			auto jsonRect = itr->value.Begin();

			float originX = static_cast<float>(jsonRect->GetDouble());
			float originY = static_cast<float>((++jsonRect)->GetDouble());
			float width = static_cast<float>((++jsonRect)->GetDouble());
			float height = static_cast<float>((++jsonRect)->GetDouble());

			inputRectangles = Rect(originX, originY,
									width, height);

			m_rectanglePaths.insert({ itr->name.GetString(),
										inputRectangles });
		}

	}

	//*/

	/*
	m_rectanglePaths["BONUS_RECT"] = { 0, 0, 100, 100 };
	m_rectanglePaths["GRENADE_RECT"] =  {0, 0, 30, 30};
	m_rectanglePaths["GRENADE_SHOOT_DEATH_RECT"] = {0, 0, 60, 60};
	m_rectanglePaths["PLASMA_SHOOT_RECT"] = {0, 0, 35, 45};
	m_rectanglePaths["PLASMA_SHOOT_DEATH_RECT"] = {0, 0, 60, 60};
	m_rectanglePaths["HEALTH_BAR_RECT"] = {0, 0, 50, 5};
	m_rectanglePaths["MARINE_RECT"] = {0, 0, 60, 60};
	m_rectanglePaths["MARINE_SHOOT_RECT"] = {0, 0, 8, 49};
	m_rectanglePaths["MARINE_DEATH_RECT"] = {0, 0, 60, 60};
	m_rectanglePaths["MELEE_SHOOT_RECT"] = {0, 0, 10, 10};
	m_rectanglePaths["ZERGLING_RECT"] = {0, 0, 60, 60};
	m_rectanglePaths["ZERGLING_DEATH_RECT"] = {0, 0, 60, 60};
	m_rectanglePaths["HYDRALISK_RECT"] = {0, 0, 107, 100};
	m_rectanglePaths["HYDRALISK_DEATH_RECT"] = {0, 0, 107, 100};
	m_rectanglePaths["HYDRALISK_SHOOT_RECT"] = {0, 0, 8, 32};
	//*/
	

}

void GameScreen::ReadGameConstants(const string & jsonFileName)
{
	///*
		ifstream inputFile(jsonFileName);

	if (inputFile.is_open())
	{
		string content;
		WriteContent(inputFile, content);

		Document value;
		value.Parse(content.c_str());

		auto constants = value.MemberBegin();
		auto integers = constants->value.Begin();

		for (auto itr = integers; itr != constants->value.End(); ++itr)
		{
			auto object = itr->MemberBegin();
			m_gameIntConstats.insert({ object->name.GetString(),
										object->value.GetInt() });
		}


		auto floats = ++constants;
		auto floatConstants = floats->value.Begin();

		for (auto itr = floatConstants; itr != floats->value.End(); ++itr)
		{
			auto object = itr->MemberBegin();
			m_gameFloatConstats.insert({ object->name.GetString(),
										static_cast<float>(object->value.GetDouble()) });
		}

		auto soundsFeatures = ++floats;
		auto soundsFeaturesArray = soundsFeatures->value.Begin();
		for (auto itr = soundsFeaturesArray; itr != soundsFeatures->value.End(); ++itr)
		{
			
			auto object = itr->MemberBegin();

			auto arrayObject = object->value.Begin();
			SSoundFeatures features(static_cast<float>(arrayObject->GetDouble())
				, static_cast<float>((++arrayObject)->GetDouble())
				, static_cast<float>((++arrayObject)->GetDouble()));

			m_soundsFeatures.insert({ object->name.GetString(),
										features });
		}
	}


	//*/

	/*
		m_gameIntConstats["kTagTileMap"] = 2;
	m_gameIntConstats["levelInterface"] = -1;
	m_gameIntConstats["levelObjects"] = -2;
	m_gameIntConstats["levelMap"] = -3;
	m_gameIntConstats["AMOUNT_MOVE_ANIMATIONS"] = 8;
	m_gameIntConstats["AMOUNT_FRAMES_FOR_MOVE"] = 5;
	m_gameIntConstats["AMOUNT_FRAMES_FOR_ATTACK"] = 4;
	m_gameIntConstats["AMOUNT_EFFECT_ANIMATIONS"] = 1;
	m_gameIntConstats["AMOUNT_FRAMES_FOR_EFFECT"] = 5;

	//m_gameFloatConstats[""] = ;

	// TODO: set constants either there or in JSON
	m_soundsFeatures["LAUNCH"] = {1.0, 0.0, 0.1f};
	m_soundsFeatures["DEATH"] = { 1.0, 0.0, 1.0 };
	m_soundsFeatures["ACTIVATE"] = { 1.0, 0.0, 0.05f };

	*/

}

void GameScreen::ReadTimeLiveEffects(const std::string & jsonFileName)
{
	///*
		ifstream inputFile(jsonFileName);

	if (inputFile.is_open())
	{
		string content;		
		WriteContent(inputFile, content);

		Document value;
		value.Parse(content.c_str());


		auto constants = value.MemberBegin();

		auto floats = constants->value.Begin();

		for (auto itr = floats; itr != constants->value.End(); ++itr)
		{
			auto object = itr->MemberBegin();
			m_timeLiveEffects.insert({ object->name.GetString(),
				static_cast<float>(object->value.GetDouble()) });
		}
	}

	//*/

	/*
		m_timeLiveEffects["MARINE_DEATH_TIME"] = 1.0;
	m_timeLiveEffects["ZERGLING_DEATH_TIME"] = 1.0;
	m_timeLiveEffects["HYDRALISK_DEATH_TIME"] =  1.0;
	m_timeLiveEffects["GRENADE_SHOOT_DEATH_TIME"] =  0.5;
	m_timeLiveEffects["PLASMA_SHOOT_DEATH_TIME"] = 0.5;

	//*/

}

void GameScreen::ReadTimeAnimations(const std::string & jsonFileName)
{

	///*
	ifstream inputFile(jsonFileName);

	if (inputFile.is_open())
	{
		string content;


		WriteContent(inputFile, content);

		Document value;
		value.Parse(content.c_str());

		auto constants = value.MemberBegin();

		for (auto itr = constants; itr != value.MemberEnd(); ++itr)
		{
			auto pairNameTime = itr->value.Begin();

			for (auto itrAnim = pairNameTime; itrAnim != itr->value.End(); ++itrAnim)
			{
				auto object = itrAnim->MemberBegin();
				string name = object->name.GetString();
				float floatValue = static_cast<float>(object->value.GetDouble());

				m_timeAnimations.insert({ name,floatValue });
			}
		}

	}

//*/

	/*
		m_timeAnimations["MARINE_MOVE_TIME"] = 1.0;
	m_timeAnimations["ZERGLING_MOVE_TIME"] = 1.0;
	m_timeAnimations["HYDRALISK_MOVE_TIME"] = 1.0;

	m_timeAnimations["MARINE_DEATH_TIME"] = 1.0;
	m_timeAnimations["ZERGLING_DEATH_TIME"] = 1.0;
	m_timeAnimations["HYDRALISK_DEATH_TIME"] = 1.0;
	m_timeAnimations["GRENADE_SHOOT_DEATH_TIME"] = 0.5;
	m_timeAnimations["PLASMA_SHOOT_DEATH_TIME"] = 0.5;

	m_timeAnimations["MARINE_ATTACK_TIME"] = 1.0;
	m_timeAnimations["ZERGLING_ATTACK_TIME"] = 1.0;
	m_timeAnimations["HYDRALISK_ATTACK_TIME"] = 1.0;

	*/


}

void GameScreen::ReadSoundsPath(const string & jsonFileName)
{
	///*
		ifstream inputFile(jsonFileName);

	if (inputFile.is_open())
	{
		string content;

		WriteContent(inputFile, content);

		Document value;
		value.Parse(content.c_str());

		auto objects = value.MemberBegin();

		string path = objects->value.GetString();

		auto pathsSoundsObject = (++objects)->value.Begin();

		vector<string> inputPaths;
		for (auto itr = pathsSoundsObject; itr != objects->value.End(); ++itr)
		{
			auto jsonPaths = itr->MemberBegin()->value.Begin();

			for (auto itrPath = jsonPaths; itrPath != itr->MemberBegin()->value.End(); ++itrPath)
			{
				inputPaths.push_back(path + itrPath->GetString());
			}

			m_soundsPaths.insert({ itr->MemberBegin()->name.GetString(),
									inputPaths });
			inputPaths.clear();

		}

	}

	//*/

	/*
	string path = "iphone/GameScene/Sounds/";
	m_soundsPaths["MARINE_SHOOT"] =
	{
		path + "Marine_AttackLaunch0.wav"
		, path + "Marine_AttackLaunch1.wav"
		, path + "Marine_AttackLaunch2.wav"
		, path + "Marine_AttackLaunch3.wav"
		, path + "Marine_AttackLaunch4.wav"
		, path + "Marine_AttackLaunch5.wav"
		, path + "Marine_AttackLaunch6.wav"
	};
	m_soundsPaths["MARINE_DEATH"] =
	{
		path + "Marine_Death01.wav",
		path + "Marine_Death02.wav",
		path + "Marine_Death03.wav",
		path + "Marine_Death04.wav",
		path + "Marine_Death05.wav",
		path + "Marine_Death06.wav",
		path + "Marine_Death07.wav"
	};

	m_soundsPaths["BONUS_ACTIVATE"] =
	{
		path + "UI_ArcadeSelect_1.wav"
   , path + "UI_ArcadeSelect_2.wav"
   , path + "UI_ArcadeSelect_3.wav"
   , path + "UI_ArcadeSelect_4.wav"
	};

	m_soundsPaths["ZERGLING_SHOOT"] =
	{
		path + "Zergling_AttackLaunch7.wav"
	};

	m_soundsPaths["ZERGLING_DEATH"] =
	{
		path + "Zergling_Death0.wav"
	,path + "Zergling_Death1.wav"
	,path + "Zergling_Death2.wav"
	,path + "Zergling_Death3.wav"
	,path + "Zergling_Death4.wav"
	};

	m_soundsPaths["HYDRALISK_SHOOT"] =
	{
		path + "Hydralisk_AttackLaunchRanged0.wav"
	,path + "Hydralisk_AttackLaunchRanged1.wav"
	, path + "Hydralisk_AttackLaunchRanged2.wav"
	, path + "Hydralisk_AttackLaunchRanged3.wav"
	};

	m_soundsPaths["HYDRALISK_DEATH"] =
	{
		path + "Hydralisk_Death0.wav"
	,path + "Hydralisk_Death1.wav"
	,path + "Hydralisk_Death2.wav"
	,path + "Hydralisk_Death3.wav"
	,path + "Hydralisk_Death4.wav"
	, path + "Hydralisk_Death5.wav"
	};

	m_soundsPaths["GRENADE_SHOOT"] =
	{
		path + "Viking_FighterAttackLaunch0.wav"
	, path + "Viking_FighterAttackLaunch1.wav"
	, path + "Viking_FighterAttackLaunch2.wav"
	};

	m_soundsPaths["PLASMA_SHOOT"] =
	{
		path + "Battlecruiser_AttackLaunch0.wav"
	,path + "Battlecruiser_AttackLaunch1.wav"
	, path + "Battlecruiser_AttackLaunch2.wav"
	};

	//*/
	
}

void GameScreen::WriteContent(ifstream & inputFile, string & content)
{
	try
	{
		string input;
		
		while (!inputFile.eof())
		{
			getline(inputFile, input);
			content += input;
		}
	}
	catch (...)
	{

	}
	
}