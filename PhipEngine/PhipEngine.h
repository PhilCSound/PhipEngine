#pragma once
#include "SFML/Graphics.hpp"
#include "EntityManager.h"
#include "SceneManager.h"
#include "Scene.h"
#include <memory>
#include <string>

class PhipEngine
{

public:
	//Member Functions
	PhipEngine(std::string _title, unsigned int _width = 800, unsigned int _height = 600);
	void LimitFramerate(unsigned int numFrames);
	const bool IsRunning();
	void Run();

	//Member Variables
	EntityManager EntityMan;
	SceneManager SceneMan;

private:
	//Member Functions
	void ClearScreen(sf::Color _color = sf::Color::Transparent);
	void Draw();
	void HandleInput();
	void Update(); //TODO Implement timing...


	//Member Variables
	sf::RenderWindow window;
	bool isRunning = true;
	unsigned int frameRate = 60;
};