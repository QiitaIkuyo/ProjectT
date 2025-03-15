#include "GameScene.h"
#include "../Game/Mouse.h"

bool GameScene::Initialize()
{
	p_UI = std::make_shared<UI>();
	p_UI->Initialize();

	p_Text = std::make_shared<Text>("Assets/CSV/ex_csvfile.csv");

	isRenderUI = true;
	lastClickTime = GetNowCount(); // 初期化時の時間を記録

	return false;
}

void GameScene::Update()
{
	p_Text->Update();
	p_UI->Update();

	if (GetKeyState('Q'))
	{
		exit(true);
	}
	UIHide();
}

void GameScene::UIHide()
{
	int currentTime = GetNowCount(); // 現在の時間を取得

	if (Mouse::IsRightButtonPressed() && (currentTime - lastClickTime) > clickInterval)
	{
		isRenderUI = !isRenderUI; // UIの表示/非表示を切り替え
		lastClickTime = currentTime; // 最後にクリックされた時間を更新
	}
}

void GameScene::Render()
{
	p_Text->Render();
	if (isRenderUI)
	{
		p_UI->Render();
		p_Text->RenderText();
	}
}
