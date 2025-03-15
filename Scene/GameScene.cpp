#include "GameScene.h"
#include "../Game/Mouse.h"

bool GameScene::Initialize()
{
	p_UI = std::make_shared<UI>();
	p_UI->Initialize();

	p_Text = std::make_shared<Text>("Assets/CSV/ex_csvfile.csv");

	isRenderUI = true;
	lastClickTime = GetNowCount(); // ���������̎��Ԃ��L�^

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
	int currentTime = GetNowCount(); // ���݂̎��Ԃ��擾

	if (Mouse::IsRightButtonPressed() && (currentTime - lastClickTime) > clickInterval)
	{
		isRenderUI = !isRenderUI; // UI�̕\��/��\����؂�ւ�
		lastClickTime = currentTime; // �Ō�ɃN���b�N���ꂽ���Ԃ��X�V
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
