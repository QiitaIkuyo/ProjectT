#include "DxLib.h"
#include "Scene/SceneManager.h"

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);

	SetUseDirect3DVersion(DX_DIRECT3D_9EX);

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}
	
	// 描画先を裏画面にする
	SetDrawScreen(DX_SCREEN_BACK);

	SetGraphMode(1920, 1080, 32);

	SceneManager::TransitionScene(Title);
	
	SceneManager::Initialize();
	
	// while(裏画面を表画面に反映, メッセージ処理, 画面クリア)
	while ((ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)) 
	{
		ClearDrawScreen();

		SceneManager::Update();
		SceneManager::Render();

		ScreenFlip();
	}

	DxLib_End();

	return 0;				// ソフトの終了 
}