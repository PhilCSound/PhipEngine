#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

class PhipEngine;
class Scene
{
public:
	virtual void Draw(sf::RenderWindow& _window) = 0;
	virtual void HandleInput(sf::RenderWindow& _window) = 0;
	virtual void Update(PhipEngine& _engine) = 0;
	virtual void Simulate(int _numFrames) = 0;
	virtual void LoadResources() = 0;
	virtual void UnloadResources() = 0;

private:
	bool IsPaused = false;
	bool HasEnded = false;
	int CurrentFrame = 0;
};