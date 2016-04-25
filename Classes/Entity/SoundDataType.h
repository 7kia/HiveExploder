#pragma once

#include "cocos2d.h"

#include <unordered_map>

struct SSoundFeatures
{
	SSoundFeatures();
	SSoundFeatures(float pitch, float pan, float gain);
	float pitch = 1.f;
	float pan = 0.f;
	float gain = 1.f;
};

typedef std::unordered_map<std::string, std::vector<std::string>> MapPaths;
typedef std::unordered_map<std::string, SSoundFeatures> MapSoundsFeatures;

class CSoundDataType
{
public:
	void										SetSounds(const std::string & key,
																std::vector<std::string> & nameSound);
	const std::vector<std::string>&					GetSounds(const std::string & key) const;

	void										SetSoundsFeatures(const SSoundFeatures & features);
	const SSoundFeatures &						GetSoundsFeatures() const;
	// TODO : there not enough functional
private:
	MapPaths									m_path;
	SSoundFeatures								m_soundFeatures;
};