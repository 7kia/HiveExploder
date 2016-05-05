#include "ReadJson.h"

using namespace std;
using namespace cocos2d;
using namespace rapidjson;

void GameScreen::ReadTexturePaths(const string & jsonFileName)
{
	ifstream inputFile(jsonFileName);

	//Document document;
	//document.ParseStream<0, UTF8<>, FileReadStream>(is);
	//string content;
//	FileUtils::getInstance()->getDataFromFile(jsonFileName).copy(content.data, 65526);

	if (inputFile.is_open())
	{

		string content;
		string input;

		while (getline(inputFile, input))
		{
			content += input;
		}

		//json_spirit::Value value;
		//read(inputFile, value);
		/*

		static const char* kTypeNames[] =
		{ "Null", "False", "True", "Object", "Array", "String", "Number" };
		for (Value::ConstMemberIterator itr = document.MemberBegin();
		itr != document.MemberEnd(); ++itr)
		{
		printf("Type of member %s is %s\n",
		itr->name.GetString(), kTypeNames[itr->value.GetType()]);
		}
		*/
		Document value;
		value.Parse(content.c_str());

		auto dictionaryPaths = value.MemberBegin();// .get_obj();

		string path = dictionaryPaths->value.GetString();
		for (auto itr = ++dictionaryPaths; itr != value.MemberEnd(); ++itr)
		{
			m_texturePaths.emplace(itr->name.GetString(),
									path + itr->value.GetString());
		}

	}

}

void GameScreen::ReadRectangles(const string & jsonFileName)
{
	ifstream inputFile(jsonFileName);

	if (inputFile.is_open())
	{

		string content;
		string input;

		while (getline(inputFile, input))
		{
			content += input;
		}


		//FileUtils::getInstance()->getDataFromFile(jsonFileName).copy(content, 65526);


		//if (inputFile.is_open())
		//{
			//json_spirit::Value value;
			//read(inputFile, value);

			//auto dictionaryPaths = value.get_obj();

		Document value;
		value.Parse(content.c_str());

		auto dictionaryPaths = value.MemberBegin();// .get_obj();

		Rect inputRectangles;
		//json_spirit::Value
		//vector<UTF_8<>> jsonRect;
		for (auto itr = dictionaryPaths; itr != value.MemberEnd(); ++itr)
		{
			auto jsonRect = itr->value.Begin();//get_array();

			float originX = static_cast<float>(jsonRect->GetDouble());
			float originY = static_cast<float>((++jsonRect)->GetDouble());
			float width = static_cast<float>((++jsonRect)->GetDouble());
			float height = static_cast<float>((++jsonRect)->GetDouble());

			inputRectangles = Rect(originX, originY,
									width, height);

			m_rectanglePaths.insert({ itr->name.GetString(),
										inputRectangles });
		}

		//}
	}

}

void GameScreen::ReadGameConstants(const string & jsonFileName)
{
	ifstream inputFile(jsonFileName);

	if (inputFile.is_open())
	{

		string content;
		string input;

		while (getline(inputFile, input))
		{
			content += input;
		}

		//json_spirit::Value value;
		//read(inputFile, value);

		//string content;
		//FileUtils::getInstance()->getDataFromFile(jsonFileName).copy(*content.data, 65526);

		Document value;
		value.Parse(content.c_str());

		auto constants = value.MemberBegin();// .get_obj();
		auto integers = constants->value.Begin();
		//auto intConstants = integers->Begin();//.value_.get_array();

		for (auto itr = integers; itr != constants->value.End(); ++itr)
		{
			auto object = itr->MemberBegin();//.get_obj();
			m_gameIntConstats.insert({ object->name.GetString(),
										object->value.GetInt() });
		}


		auto floats = ++constants;
		auto floatConstants = floats->value.Begin();//.value_.get_array();

		for (auto itr = floatConstants; itr != floats->value.End(); ++itr)
		{
			auto object = itr->MemberBegin();//.get_obj();
			m_gameIntConstats.insert({ object->name.GetString(),
										static_cast<float>(object->value.GetDouble()) });
		}

		auto soundsFeatures = ++floats;
		auto soundsFeaturesArray = soundsFeatures->value.Begin();
		for (auto itr = soundsFeaturesArray; itr != soundsFeatures->value.End(); ++itr)
		{
			
			auto object = itr->MemberBegin();//.get_obj();
			//auto object = soundsFeaturesArray.at(index).get_obj();
			auto arrayObject = object->value.Begin();// object.at(0).value_.get_array();
			SSoundFeatures features(static_cast<float>(arrayObject->GetDouble())
				, static_cast<float>((++arrayObject)->GetDouble())
				, static_cast<float>((++arrayObject)->GetDouble()));

			m_soundsFeatures.insert({ object->name.GetString(),
										features });
		}
	}

}

void GameScreen::ReadTimeLiveEffects(const std::string & jsonFileName)
{
	ifstream inputFile(jsonFileName);

	if (inputFile.is_open())
	{
		string content;
		string input;

		while (getline(inputFile, input))
		{
			content += input;
		}

		//json_spirit::Value value;
		//read(inputFile, value);

		//string content;
		//FileUtils::getInstance()->getDataFromFile(jsonFileName).copy(*content.data, 65526);

		Document value;
		value.Parse(content.c_str());


		auto constants = value.MemberBegin();// .get_obj();

		auto floats = constants->value.Begin();//constants.at(0);
		//auto floatConstants = floats->Begin();//floats.value_.get_array();
		for (auto itr = floats; itr != constants->value.End(); ++itr)
		{
			auto object = itr->MemberBegin();//get_obj();
			m_timeLiveEffects.insert({ object->name.GetString(),
				static_cast<float>(object->value.GetDouble()) });
		}
	}
}

void GameScreen::ReadTimeAnimations(const std::string & jsonFileName)
{
	ifstream inputFile(jsonFileName);

	if (inputFile.is_open())
	{
		string content;
		string input;

		while (getline(inputFile, input))
		{
			content += input;
		}

		//json_spirit::Value value;
		//read(inputFile, value);

		//string content;
		//FileUtils::getInstance()->getDataFromFile(jsonFileName).copy(*content.data, 65526);

		Document value;
		value.Parse(content.c_str());

		auto constants = value.MemberBegin();// .get_obj();

			//for (size_t index = 0; index < 3; index++)
			//{
			
			//auto pairNameTime = times->Begin();//.value_.get_array();

			for (auto itr = constants; itr != value.MemberEnd(); ++itr)
			{
				auto pairNameTime = itr->value.Begin();
				//auto animations = itr;//.at(index);
				//auto floatConstants = animations.value_.get_array();
				for (auto itrAnim = pairNameTime; itrAnim != itr->value.End(); ++itrAnim)
				{
					auto object = itrAnim->MemberBegin();// .get_obj();
					string name = object->name.GetString();
					float floatValue = static_cast<float>(object->value.GetDouble());

					m_timeAnimations.insert({ name,floatValue });
				}
			}
			//}		

		

	}
}

void GameScreen::ReadSoundsPath(const string & jsonFileName)
{
	ifstream inputFile(jsonFileName);

	if (inputFile.is_open())
	{
		string content;
		string input;

		while (getline(inputFile, input))
		{
			content += input;
		}

		//json_spirit::Value value;
		//read(inputFile, value);

		//auto objects = value.get_obj();
		///string content;
		//FileUtils::getInstance()->getDataFromFile(jsonFileName).copy(*content.data, 65526);

		Document value;
		value.Parse(content.c_str());

		auto objects = value.MemberBegin();// .get_obj();

			//auto pathObject = objects->value;
		string path = objects->value.GetString();

		auto pathsSoundsObject = (++objects)->value.Begin();//_.get_array();


		vector<string> inputPaths;
		for (auto itr = pathsSoundsObject; itr != objects->value.End(); ++itr)
		{
			//auto vectorPaths = pathsSoundsObject//.at(index).get_obj();
			auto jsonPaths = itr->MemberBegin()->value.Begin();//vectorPaths.at(0).value_.get_array();

			for (auto itrPath = jsonPaths; itrPath != itr->MemberBegin()->value.End(); ++itrPath)
			{
				inputPaths.push_back(path + itrPath->GetString());
			}

			m_soundsPaths.insert({ itr->MemberBegin()->name.GetString(),
									inputPaths });
			inputPaths.clear();

		}

	}

}