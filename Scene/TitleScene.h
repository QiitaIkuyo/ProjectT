#pragma once
#include "DxLib.h"
#include "../Scene/BaseScene.h"

using namespace std;

class TitleScene : public BaseScene
{
public:

	TitleScene() {};
	~TitleScene() {};

	bool Initialize() override { return true; }; // 初期化
	void Update()override {}; // 更新
	void Render()override {}; // 描画

private:


};