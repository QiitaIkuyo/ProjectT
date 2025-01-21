#include "GameScene.h"

#include "../Object/Text.h"

bool GameScene::Initialize()
{
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
	CSVPathAssign("Assets/CSV/ex_csvfile.csv");
}
