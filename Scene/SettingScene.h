#pragma once
#include "DxLib.h"
#include "../Scene/BaseScene.h"

using namespace std;

class SettingScene : public BaseScene
{
public:

	bool Initialize() override; // 初期化
	void Update() override; // 更新
	void Render() override; // 描画

private:

	int exitButton;
	int eb_posX = 500;
	int eb_posY = 900;
	void EBClick();

	int mx, my;
	int mouseX, mouseY;
};