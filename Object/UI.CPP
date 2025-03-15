#include "UI.h"
#include "DxLib.h"
#include <cmath>

float EaseInOutQuart(float t)
{
	if (t < 0.5f)
	{
		return 8.0f * t * t * t * t;
	}
	else
	{
		float f = (t - 1.0f);
		return -8.0f * f * f * f * f + 1.0f;
	}
}

void UI::Initialize()
{
	messageWindow = LoadGraph("Assets/Karisozai/MESSAGE_WINDOW.png");
	if (messageWindow == -1)
	{
		MessageBox(NULL, "画像の読み込みに失敗しました", "エラー", MB_OK);
	}
	magnifyingGlass = LoadGraph("Assets/Karisozai/U_Musimegane.png");
	if (magnifyingGlass == -1)
	{
		MessageBox(NULL, "画像の読み込みに失敗しました", "エラー", MB_OK);
	}

	alphaValue = 255; // 初期アルファ値を設定
	increasing = false; // アルファ値が増加中かどうかを示すフラグを初期化
	rotationAngle = 0.0f; // 初期回転角度を設定
	rotatingClockwise = true; // 時計回りに回転中かどうかを示すフラグを初期化
	rogoInterbal = 0; // 回転角度を更新する間隔を設定
	alphaTime = 0.0f; // アルファ値を更新する間隔を設定
}

void UI::Update()
{
	// --- ロゴ点滅 ---//
	 UpdateAlphaValue();

	// --- ロゴ回転 ---//
	//UpdateRotation();

	rogoInterbal -= 1.0f; // 回転角度を更新する間隔を減少
}

void UI::Render()
{
	if (messageWindow != -1)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
		DrawGraph(0, 350, messageWindow, TRUE);

		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}

	// --- magnifyingGlassを点滅させて描画 --- //
	if (magnifyingGlass != -1)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, alphaValue);
		DrawGraph(0, 350, magnifyingGlass, TRUE); // 描画位置を調整

		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
	// -----------------------------------//

	// --- magnifyingGlassを回転させて描画 --- //
	//if (magnifyingGlass != -1)
	//{
	//	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);

	//	// magnifyingGlassを回転させて描画
	//	int centerX = 1700; // 回転の中心X座標
	//	int centerY = 600; // 回転の中心Y座標
	//	int drawX = centerX; // 描画位置X座標
	//	int drawY = 350 + centerY; // 描画位置Y座標
	//	DrawRotaGraph(drawX, drawY, 1.0, rotationAngle, magnifyingGlass, TRUE);

	//	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	//}
}

void UI::UpdateAlphaValue()
{
	// アルファ値をイージング関数で更新
	if (increasing)
	{
		alphaTime += 0.01f; // 時間を進める
		if (alphaTime > 1.0f)
		{
			alphaTime = 1.0f;
			increasing = false; // 増加が終わったら減少に切り替え
		}
	}
	else
	{
		alphaTime -= 0.01f; // 時間を戻す
		if (alphaTime < 0.0f)
		{
			alphaTime = 0.0f;
			increasing = true; // 減少が終わったら増加に切り替え
		}
	}
	alphaValue = 255.0f * EaseInOutQuart(alphaTime); // イージング関数でアルファ値を更新
}


//void UI::UpdateRotation()
//{
//	// 回転角度を更新
//	if (rogoInterbal < 0)
//	{
//		if (rotatingClockwise)
//		{
//			rotationAngle += 0.003f; // 時計回りに回転
//			if (rotationAngle >= DX_PI / 12) // 45度に達したら反転
//			{
//				rotatingClockwise = false;
//			}
//		}
//		else
//		{
//			rotationAngle -= 0.03f; // 反時計回りに回転
//			if (rotationAngle <= -DX_PI / 12) // -45度に達したら反転
//			{
//				rotatingClockwise = true;
//				rogoInterbal = 100.0f; // 回転角度を更新する間隔を設定
//			}
//		}
//	}
//}