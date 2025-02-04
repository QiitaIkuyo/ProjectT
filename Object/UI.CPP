#include "UI.h"

void UI::Initialize()
{
	messageWindow = LoadGraph("Assets/Karisozai/01.png");
}

void UI::Update()
{

}

void UI::Render()
{
	if (messageWindow != -1)
	{
		DrawGraph(100,750, messageWindow, true);
	}
}
