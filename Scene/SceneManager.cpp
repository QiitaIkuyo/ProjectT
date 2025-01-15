#include "SceneManager.h"
#include "TitleScene.h"
#include "GameScene.h"
#include "SettingScene.h"
#include <memory>

using namespace std;

unique_ptr<BaseScene> SceneManager::sceneName = nullptr;

void SceneManager::TransitionScene(Scene agoScene)
{
	switch (agoScene)
	{
	case Scene::Title:
		sceneName = make_unique<TitleScene>();
		break;
	case Scene::Game:
		sceneName = make_unique<GameScene>();
		break;
	case Scene::Setting:
		sceneName = make_unique<SettingScene>();
		break;
	default:
		break;
	}
	Initialize();
}

bool SceneManager::Initialize()
{
	sceneName->Initialize();
	return false;
}

void SceneManager::Update()
{
	sceneName->Update();
}

void SceneManager::Render()
{
	sceneName->Render();
}

