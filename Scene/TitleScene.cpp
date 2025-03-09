#include "TitleScene.h"
#include "../Scene/SceneManager.h"
#include "../Game/Mouse.h"

bool TitleScene::Initialize()
{
	startButton = LoadGraph("Assets/Karisozai/TitleStart.png");
	if (startButton == -1)
	{
		MessageBox(NULL, "‰æ‘œ‚Ì“Ç‚Ýž‚Ý‚ÉŽ¸”s‚µ‚Ü‚µ‚½", "ƒGƒ‰[", MB_OK);
	}

	settingButton = LoadGraph("Assets/Karisozai/TitleSetting.png");
	if (settingButton == -1)
	{
		MessageBox(NULL, "‰æ‘œ‚Ì“Ç‚Ýž‚Ý‚ÉŽ¸”s‚µ‚Ü‚µ‚½", "ƒGƒ‰[", MB_OK);
	}
	
	exitButton = LoadGraph("Assets/Karisozai/TitleExit.png");
	if (exitButton == -1)
	{
		MessageBox(NULL, "‰æ‘œ‚Ì“Ç‚Ýž‚Ý‚ÉŽ¸”s‚µ‚Ü‚µ‚½", "ƒGƒ‰[", MB_OK);
	}

	return true;
}	

void TitleScene::Update()
{
	GetMousePoint(&mouseX, &mouseY);

	SBClick();
	STBClick();
	EBClick();
}

void TitleScene::Render()
{
	if (startButton != -1)
	{
		DrawGraph(sb_posX, sb_posY, startButton, TRUE);
	}
	
	if (settingButton != -1)
	{
		DrawGraph(stb_posX, stb_posY, settingButton, TRUE);
	}

	if (exitButton != -1)
	{
		DrawGraph(eb_posX, eb_posY, exitButton, TRUE);
	}

	DrawString(0, 0, "TitleScene", GetColor(255, 255, 255));

}


void TitleScene::SBClick()
{
	int sb_scaX = 150, 
		sb_scaY = 100;

	if (Mouse::IsLeftButtonPressed() == 1 &&
		mouseX >= sb_posX && mouseX <= sb_posX + sb_scaX &&
		mouseY >= sb_posY && mouseY <= sb_posY + sb_scaY)
	{
		SceneManager::TransitionScene(Game);
	}
}

void TitleScene::STBClick()
{
	int stb_scaX = 150,
		stb_scaY = 100;

	if (Mouse::IsLeftButtonPressed() == 1 &&
		mouseX >= stb_posX && mouseX <= stb_posX + stb_scaX &&
		mouseY >= stb_posY && mouseY <= stb_posY + stb_scaY)
	{
		SceneManager::TransitionScene(Setting);
	}
}

void TitleScene::EBClick()
{
	int eb_scaX = 150,
		eb_scaY = 100;

	if (Mouse::IsLeftButtonPressed() == 1 &&
		mouseX >= eb_posX && mouseX <= eb_posX + eb_scaX &&
		mouseY >= eb_posY && mouseY <= eb_posY + eb_scaY)
	{
		exit(0);
	}
}
