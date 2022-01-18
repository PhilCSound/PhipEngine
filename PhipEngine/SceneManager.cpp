#include "SceneManager.h"


void SceneManager::AddScene(std::string & _name, std::shared_ptr<Scene> _scene)
{
	if (scenes.size() == 0)
	{
		scenes.insert(std::make_pair(_name, _scene));
		currentScene = _name;
		_scene->LoadResources();
	}
	else
		scenes.insert(std::make_pair(_name, _scene));
}

void SceneManager::SwapToScene(std::string & _name, std::shared_ptr<Scene> _scene)
{
	scenes.insert(std::make_pair(_name, _scene));
	swapScenes = true;
	sceneToSwapTo = _name;
}

void SceneManager::HandleSceneChanges()
{
	if (swapScenes == true)
	{
		swapScenes = false;
		scenes.at(currentScene)->UnloadResources();
		scenes.erase(currentScene);
		scenes.at(sceneToSwapTo)->LoadResources();
		currentScene = sceneToSwapTo;
		sceneToSwapTo = "";
	}
}

std::shared_ptr<Scene> SceneManager::GetCurrentScene()
{
	if (scenes.size() == 0)
		return 0;
	return scenes.at(currentScene);
}
