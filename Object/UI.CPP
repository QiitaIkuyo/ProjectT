#include "UI.h"

void UI::Initialize()
{
	messageWindow = LoadGraph("Assets/Karisozai/Window.png");
	if (messageWindow == -1)
	{
		MessageBox(NULL, "‰æ‘œ‚Ì“Ç‚İ‚İ‚É¸”s‚µ‚Ü‚µ‚½", "ƒGƒ‰[", MB_OK);
	}
}

void UI::Update()
{

}

void UI::Render()
{
	if (messageWindow != -1)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
		DrawGraph(0,350,messageWindow, TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
}
