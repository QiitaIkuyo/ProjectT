#pragma once
#include "DxLib.h"
#include "../Scene/BaseScene.h"

using namespace std;

class GameScene : public BaseScene
{
public:

	GameScene() {};
	~GameScene() {};

	bool Initialize() override; // 初期化
	void Update() override; // 更新
	void Render() override; // 描画

private:


};