#include "ResourceManager.h"

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
void ResourceManager::UnloadTexture(const std::string & _name)
{
	textureMap.erase(_name);
}

bool ResourceManager::ContainsTexture(const std::string & _name)
{
	if (textureMap.count(_name) == 0)
		return false;
	return true;
}

sf::Texture & ResourceManager::GetTexture(const std::string & _name)
{
	if (ContainsTexture(_name))
		return textureMap.at(_name);
	sf::Texture _text;
	return _text;
}
