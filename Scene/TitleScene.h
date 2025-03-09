#pragma once
#include "DxLib.h"
#include "../Scene/BaseScene.h"

using namespace std;

class TitleScene : public BaseScene
{
public:

	TitleScene() {};
	~TitleScene() {};

	bool Initialize() override; // ‰Šú‰»
	void Update()override; // XV
	void Render()override; // •`‰æ

private:

	int startButton;
	int sb_posX = 500;
	int sb_posY = 500;;
	void SBClick();

	int settingButton;
	int stb_posX = 500;
	int stb_posY = 700;
	void STBClick();
	
	int exitButton;
	int eb_posX = 500;
	int eb_posY = 900;
	void EBClick();

	int mouseX, mouseY;
};