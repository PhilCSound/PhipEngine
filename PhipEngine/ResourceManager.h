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

	//Member functions
	bool ContainsFont(const std::string& _name);
	bool ContainsSoundBuffer(const std::string& _name);
	bool ContainsTexture(const std::string& _name);
	sf::Font& GetFont(const std::string& _name);
	sf::SoundBuffer& GetSoundBuffer(const std::string& _name);
	sf::Texture& GetTexture(const std::string& _name);
	bool LoadFont(const std::string& _path, const std::string& _name);
	bool LoadSoundBuffer(const std::string& _path, const std::string& _name);
	bool LoadTexture(const std::string& _path, const std::string& _name);
	void UnloadFont(const std::string& _name);
	void UnloadSoundBuffer(const std::string& _name);
	void UnloadTexture(const std::string& _name);

private:
	//Member Variables
	std::map<std::string, sf::Font> fontMap;
	std::map<std::string, sf::SoundBuffer> soundBufferMap;
	std::map<std::string, sf::Texture> textureMap;

};

