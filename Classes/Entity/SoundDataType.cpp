#include "SoundDataType.h"

void CSoundDataType::SetSounds(const std::string & key, std::vector<std::string>& nameSound)
{
	m_path.insert({ key, nameSound });
}

const std::vector<std::string>& CSoundDataType::GetSounds(const std::string & key) const
{
	return m_path.at(key);
}

void CSoundDataType::SetSoundsFeatures(const SSoundFeatures & features)
{
	m_soundFeatures = features;
}

const SSoundFeatures & CSoundDataType::GetSoundsFeatures() const
{
	return m_soundFeatures;
}
