#pragma once
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include <map>
#include <string>

class ResourceManager
{
public:
	ResourceManager(){}
	~ResourceManager(){}

	bool LoadTexture(const std::string& _path, const std::string& _name);
	void UnloadTexture(const std::string& _name);
	bool ContainsTexture(const std::string& _name);
	sf::Texture& GetTexture(const std::string& _name);
	
private:
	std::map<std::string, sf::Texture> textureMap;

};

