#include "GameScene.h"
#include "../Game/Mouse.h"

bool GameScene::Initialize()
{
	p_UI = std::make_shared<UI>();
	p_UI->Initialize();

	p_Text = std::make_shared<Text>("Assets/CSV/ex_csvfile.csv");
	isRenderUI = true;
	lastClickTime = GetNowCount(); // 初期化時の時間を記録

	return false;
}

void GameScene::Update()
{
	bool currentEscapeKeyState = CheckHitKey(KEY_INPUT_ESCAPE) == 1; // ESCAPEキーが押されているかどうか

	if (currentEscapeKeyState && !prevEscapeKeyState)
	{
		isScenePause = !isScenePause; // シーンのポーズを切り替え
	}

	// 現在のESCAPEキーの状態を記録
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
	RenderLogBG(); // ログの背景を描画

	}
}

void GameScene::RenderLogBG() const
{
	// アルファブレンドを有効にする
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128); // 128は半透明の度合い（0?255）

	// 画面全体を覆う半透明の黒い矩形を描画
	DrawBox(0, 0, 1920, 1080, GetColor(0, 0, 0), TRUE);

	// アルファブレンドを無効にする
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void GameScene::UIHide()
{
	int currentTime = GetNowCount(); // 現在の時間を取得

	if (Mouse::IsRightButtonPressed() && (currentTime - lastClickTime) > clickInterval)
	{
		isRenderUI = !isRenderUI; // UIの表示/非表示を切り替え
		lastClickTime = currentTime; // 最後にクリックされた時間を更新
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
