#include "GameScene.h"

bool GameScene::Initialize()
{
	return false;
}

void GameScene::Update()
{
	if(GetKeyState('Q'))
	{
		exit(true);
	}
}

void GameScene::Render()
{
}
