#pragma once
#include "DxLib.h"
#include "../Scene/BaseScene.h"

using namespace std;

class SettingScene : public BaseScene
{
public:

	bool Initialize() override; // ‰Šú‰»
	void Update() override; // XV
	void Render() override; // •`‰æ

private:

	int exitButton;
	int eb_posX = 500;
	int eb_posY = 900;
	void EBClick();

	int mx, my;
	int mouseX, mouseY;
};