#include "GameScene.h"

#include "../Object/Text.h"

bool GameScene::Initialize()
{
	p_UI = std::make_shared<UI>();
	p_UI->Initialize();

	return false;
}

void GameScene::Update()
{
	

	if (GetKeyState('Q'))
	{
		exit(true);
	}
}

void GameScene::Render()
{
	p_UI->Render();
	CSVPathAssign("Assets/CSV/ex_csvfile.csv");
}
