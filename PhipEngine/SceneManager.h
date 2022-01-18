#pragma once
#include "Scene.h"
#include <string>
#include <map>
#include <memory>

class SceneManager
{
public:

	void AddScene(std::string & _name, std::shared_ptr<Scene> _scene);
	void SwapToScene(std::string &_name, std::shared_ptr<Scene> _scene = 0);
	void HandleSceneChanges();
	std::shared_ptr<Scene> GetCurrentScene();

private:

	friend class PhipEngine;
	SceneManager() {}
	std::string currentScene = "";
	std::string sceneToSwapTo = "";
	bool swapScenes = false;
	std::map<std::string, std::shared_ptr<Scene>> scenes;


};

