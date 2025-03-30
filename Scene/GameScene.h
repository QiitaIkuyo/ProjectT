#pragma once
#include <memory>

#include "DxLib.h"
#include "../Scene/BaseScene.h"
#include "../Object/UI.h"
#include "../Object/Text.h"

using namespace std;

class GameScene : public BaseScene
{
public:

	GameScene() {};
	~GameScene() {};

	bool Initialize() override; // 初期化
	void Update() override; // 更新
	void Render() override; // 描画

private:
	
	bool isScenePause; // ポーズ
	bool prevEscapeKeyState = false; // 前回のフレームでのESCAPEキーの状態
	void RenderLog() const; // ログの描画
	void RenderLogBG() const; // ログの背景描画


	void UIHide();
	bool isRenderUI = true;
	int lastClickTime; // 最後にクリックされた時間
	const int clickInterval = 500;

	shared_ptr<UI>p_UI = nullptr;
	shared_ptr<Text>p_Text = nullptr;
};