#include "GameScene.h"
#include <boost/algorithm/string.hpp>

using namespace std;

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
	Words words;
	string inputString;

	getline(inputFile, inputString);
	words = SplitWords(inputString);
	m_texturePaths.emplace(words[0], words[1]);
	string path = m_texturePaths["PATH"];

	while (getline(inputFile, inputString))
	{
		words = SplitWords(inputString);
		if (inputString != "")
		{
			m_texturePaths.emplace(words[0], path + words[1]);
		}
		else
		{
			break;
		}
	}

	}

}
