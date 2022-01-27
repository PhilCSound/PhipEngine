#include "ResourceManager.h"


bool ResourceManager::ContainsFont(const std::string & _name)
{
	if (fontMap.count(_name) == 0)
		return false;
	return true;
}

bool ResourceManager::ContainsSoundBuffer(const std::string & _name)
{
	if (soundBufferMap.count(_name) == 0)
		return false;
	return true;
}

bool ResourceManager::ContainsTexture(const std::string & _name)
{
	if (textureMap.count(_name) == 0)
		return false;
	return true;
}

sf::Font & ResourceManager::GetFont(const std::string & _name)
{
	if (ContainsFont(_name))
		return fontMap.at(_name);
	sf::Font _font;
	return _font;
}

sf::SoundBuffer & ResourceManager::GetSoundBuffer(const std::string & _name)
{
	if (ContainsSoundBuffer(_name))
		return soundBufferMap.at(_name);
	sf::SoundBuffer _sb;
	return _sb;
}

sf::Texture & ResourceManager::GetTexture(const std::string & _name)
{
	if (ContainsTexture(_name))
		return textureMap.at(_name);
	sf::Texture _text;
	return _text;
}

bool ResourceManager::LoadFont(const std::string & _path, const std::string & _name)
{
	//TODO: Double check if this unneccessary as if a pair already exists nothing happens?
	if (ContainsFont(_name))
		return true;

	sf::Font _font;
	if (_font.loadFromFile(_path))
	{
		fontMap.insert(std::make_pair(_name, _font));
		return true;
	}
	return false;
}

bool ResourceManager::LoadSoundBuffer(const std::string & _path, const std::string & _name)
{
	//TODO: Double check if this unneccessary as if a pair already exists nothing happens?
	if (ContainsSoundBuffer(_name))
		return true;

	sf::SoundBuffer _sb;
	if (_sb.loadFromFile(_path))
	{
		fontMap.insert(std::make_pair(_name, _sb));
		return true;
	}
	return false;
}

bool ResourceManager::LoadTexture(const std::string & _path, const std::string & _name)
{
	//TODO: Double check if this unneccessary as if a pair already exists nothing happens?
	if (ContainsTexture(_name))
		return true;

	sf::Texture _texture;
	if (_texture.loadFromFile(_path))
	{
		textureMap.insert(std::make_pair(_name, _texture));
		return true;
	}
	return false;
}

//Careful: This class/function doesnt know if anything else depends on the file.
void ResourceManager::UnloadFont(const std::string & _name)
{
	fontMap.erase(_name);
}

//Careful: This class/function doesnt know if anything else depends on the file.
void ResourceManager::UnloadSoundBuffer(const std::string & _name)
{
	soundBufferMap.erase(_name);
}

//Careful: This class/function doesnt know if anything else depends on the file.
void ResourceManager::UnloadTexture(const std::string & _name)
{
	textureMap.erase(_name);
}