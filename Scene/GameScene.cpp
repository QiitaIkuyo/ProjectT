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
	bool currentEscapeKeyState = CheckHitKey(KEY_INPUT_ESCAPE) == 1; // ESCAPE�L�[��������Ă��邩�ǂ���

	if (currentEscapeKeyState && !prevEscapeKeyState)
	{
		isScenePause = !isScenePause; // �V�[���̃|�[�Y��؂�ւ�
	}

	// ���݂�ESCAPE�L�[�̏�Ԃ��L�^
	prevEscapeKeyState = currentEscapeKeyState;

	p_Text->Update();
	p_UI->Update();

	if (GetKeyState('Q'))
	{
		exit(true);
	}
	UIHide();
}

void GameScene::RenderLog() const
{


	if (isScenePause) 
	{
	RenderLogBG(); // ���O�̔w�i��`��

	}
}

void GameScene::RenderLogBG() const
{
	// �A���t�@�u�����h��L���ɂ���
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128); // 128�͔������̓x�����i0?255�j

	// ��ʑS�̂𕢂��������̍�����`��`��
	DrawBox(0, 0, 1920, 1080, GetColor(0, 0, 0), TRUE);

	// �A���t�@�u�����h�𖳌��ɂ���
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
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

	RenderLog();
}
