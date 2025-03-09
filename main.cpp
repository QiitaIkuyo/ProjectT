#include "DxLib.h"
#include "Scene/SceneManager.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);

	SetUseDirect3DVersion(DX_DIRECT3D_9EX);

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}
	
	// �`���𗠉�ʂɂ���
	SetDrawScreen(DX_SCREEN_BACK);

	SetGraphMode(1920, 1080, 32);

	SceneManager::TransitionScene(Title);
	
	SceneManager::Initialize();
	
	// while(����ʂ�\��ʂɔ��f, ���b�Z�[�W����, ��ʃN���A)
	while ((ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)) 
	{
		ClearDrawScreen();

		SceneManager::Update();
		SceneManager::Render();

		ScreenFlip();
	}

	DxLib_End();

	return 0;				// �\�t�g�̏I�� 
}