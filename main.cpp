#include "DxLib.h"
#include "Scene/SceneManager.h"

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}
	
	// 描画先を裏画面にする
	SetDrawScreen(DX_SCREEN_BACK);

	SetGraphMode(1280, 720, 32);

	SceneManager::TransitionScene(Game);
	
	SceneManager::Initialize();
	
	// while(裏画面を表画面に反映, メッセージ処理, 画面クリア)
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		SceneManager::Update();
		SceneManager::Render();
	}

	DxLib_End();

	return 0;				// ソフトの終了 
}