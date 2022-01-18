#include "PhipEngine.h"

PhipEngine::PhipEngine(std::string _title, unsigned int _width, unsigned int _height)
	: window(sf::VideoMode(_width, _height), _title)
{
}

void PhipEngine::LimitFramerate(unsigned int _numFrames)
{
	window.setFramerateLimit(_numFrames);
}

const bool PhipEngine::IsRunning()
{
	return isRunning;
}

void PhipEngine::Run()
{
	std::shared_ptr<Scene> _scene = SceneMan.GetCurrentScene();
	if (!_scene)
		HandleInput();
	else if (isRunning)
	{
		Update();
		_scene->HandleInput(window);
		_scene->Update(*this);
		ClearScreen();
		_scene->Draw(window);
		window.display();
	}
	EntityMan.Update();
	SceneMan.HandleSceneChanges();
}

void PhipEngine::ClearScreen(sf::Color _color)
{
	window.clear(_color);
}

void PhipEngine::Draw()
{
	//TODO Draw things here.
}

void PhipEngine::HandleInput()
{
	sf::Event _event;
	while (window.pollEvent(_event))
	{
		switch (_event.type)
		{
		case sf::Event::Closed:
			isRunning = false;
			window.close();
			break;
		}
	}
}

void PhipEngine::Update()
{
	//Todo implement timing.
}
