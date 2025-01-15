#pragma once

#include "BaseScene.h"
#include "TitleScene.h"
#include "GameScene.h"
#include "SettingScene.h"
#include <memory>

using namespace std;

// シーン列挙
enum Scene
{
	Title,			// TitleScene
	Game,		// GameScene
	Setting,	// SettingScene
};


// このクラスでシーン遷移を管理
class SceneManager
{
public:
	
	static bool Initialize(); // 初期化
	static void Update(); // 更新
	static void Render(); // 描画

	// 引数のシーンに遷移
	static void TransitionScene(Scene agoScene);

private:

	static std::unique_ptr<BaseScene>sceneName;
};