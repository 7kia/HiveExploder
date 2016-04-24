#include "GameScene.h"
#include <boost/algorithm/string.hpp>

using namespace std;
using namespace json_spirit;
using namespace cocos2d;

Words SplitWords(string const& text)
{
	string trimmed = boost::trim_copy(text);

	vector<string> words;
	boost::split(words, trimmed, boost::is_space(), boost::token_compress_on);
	return words;
}

void GameScreen::ReadTexturePaths(const string & jsonFileName)
{
	ifstream inputFile(jsonFileName);

	if (inputFile.is_open())
	{
		json_spirit::Value value;
		read(inputFile, value);

		auto dictionaryPaths = value.get_obj();

		string path = dictionaryPaths.at(0).value_.get_str();
		for (size_t index = 1; index < dictionaryPaths.size(); index++)
		{
			m_texturePaths.emplace(dictionaryPaths.at(index).name_,
									path + dictionaryPaths.at(index).value_.get_str());
		}

	}

}

void GameScreen::ReadRectangles(const string & jsonFileName)
{
	ifstream inputFile(jsonFileName);

	if (inputFile.is_open())
	{
		json_spirit::Value value;
		read(inputFile, value);

		auto dictionaryPaths = value.get_obj();
		Rect inputRectangles;
		vector<json_spirit::Value> jsonRect;
		for (size_t index = 0; index < dictionaryPaths.size(); index++)
		{
			jsonRect = dictionaryPaths.at(index).value_.get_array();
			inputRectangles = Rect(jsonRect.at(0).get_int(), jsonRect.at(1).get_int(),
									jsonRect.at(2).get_int(), jsonRect.at(3).get_int());

			m_rectanglePaths.insert({ dictionaryPaths.at(index).name_,
										inputRectangles });
		}

	}

}

void GameScreen::ReadGameConstants(const string & jsonFileName)
{
	ifstream inputFile(jsonFileName);

	if (inputFile.is_open())
	{
		json_spirit::Value value;
		read(inputFile, value);

		auto constants = value.get_obj();
		auto integers = constants.at(0);
		auto intConstants = integers.value_.get_array();
		///*
		for (size_t index = 0; index < intConstants.size(); index++)
		{
			auto object = intConstants.at(index).get_obj();
			m_gameIntConstats.insert({ object.at(0).name_,
										object.at(0).value_.get_int() });
		}

		//*/

		auto floats = constants.at(1);
		auto floatConstants = floats.value_.get_array();
		for (size_t index = 0; index < floatConstants.size(); index++)
		{
			auto object = floatConstants.at(index).get_obj();
			m_gameFloatConstats.insert({ object.at(0).name_,
										static_cast<float>(object.at(0).value_.get_real()) });
		}
	}

}