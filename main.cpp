#include "DxLib.h"
#include "Scene/SceneManager.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}
	
	// �`���𗠉�ʂɂ���
	SetDrawScreen(DX_SCREEN_BACK);

	SetGraphMode(1280, 720, 32);

	SceneManager::TransitionScene(Game);
	
	SceneManager::Initialize();
	
	// while(����ʂ�\��ʂɔ��f, ���b�Z�[�W����, ��ʃN���A)
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		SceneManager::Update();
		SceneManager::Render();
	}

	DxLib_End();

	return 0;				// �\�t�g�̏I�� 
}