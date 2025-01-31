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
	messageWindow = DrawGraph(0, 0, messageWindow, true);
}
