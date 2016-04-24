#include "GameScene.h"
#include <boost/algorithm/string.hpp>

using namespace std;
using namespace json_spirit;

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
		Value value;
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
