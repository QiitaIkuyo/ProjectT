#include "SettingScene.h"
#include "../Scene/SceneManager.h"
#include "../Game/Mouse.h"

bool SettingScene::Initialize()
{
	exitButton = LoadGraph("Assets/Karisozai/TitleExit.png");
	if (exitButton == -1)
	{
		MessageBox(NULL, "‰æ‘œ‚Ì“Ç‚Ýž‚Ý‚ÉŽ¸”s‚µ‚Ü‚µ‚½", "ƒGƒ‰[", MB_OK);
	}

	return false;
}

void SettingScene::Update()
{
	EBClick();
}

void SettingScene::Render()
{
	if (exitButton != -1)
	{
		DrawGraph(eb_posX, eb_posY, exitButton, TRUE);
	}

	DrawString(0, 0, "SettingScene", GetColor(255, 255, 255));
}

void SettingScene::EBClick()
{
	int eb_scaX = 150,
		eb_scaY = 100;

	GetMousePoint(&mx, &my);
	mouseX = mx;
	mouseY = my;

	if (Mouse::IsLeftButtonPressed() == 1 &&
		mouseX >= eb_posX && mouseX <= eb_posX + eb_scaX &&
		mouseY >= eb_posY && mouseY <= eb_posY + eb_scaY)
	{
		exit(0);
	}
}
