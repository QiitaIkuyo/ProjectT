#include "GameScene.h"


bool GameScene::Initialize()
{
	p_UI = std::make_shared<UI>();
	p_UI->Initialize();

	p_Text = std::make_shared<Text>("Assets/CSV/ex_csvfile.csv");

	return false;
}

void GameScene::Update()
{
	p_Text->Update();

	if (GetKeyState('Q'))
	{
		exit(true);
	}
}

void GameScene::Render()
{
	p_UI->Render();
	p_Text->Render();
}
