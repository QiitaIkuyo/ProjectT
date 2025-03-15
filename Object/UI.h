#pragma once
#pragma once

#include "DxLib.h"
#include <memory>

using namespace std;

class UI
{
public:
	UI() {};
	~UI() {  };

	// 初期化・更新など
	void Initialize();
	void Update();
	void Render();

private:
	int messageWindow;
	int magnifyingGlass;

	void UpdateAlphaValue(); // アルファ値を更新するメンバ関数
	int alphaValue; // アルファ値を保持するメンバ変数
	bool increasing; // アルファ値が増加中かどうかを示すフラグ
	float alphaTime; // アルファ値を更新する間隔

	void UpdateRotation(); // 回転角度を更新するメンバ関数
	float rotationAngle; // 回転角度を保持するメンバ変数
	float rogoInterbal; // 回転角度を更新する間隔
	bool rotatingClockwise; // 時計回りに回転中かどうかを示すフラグ
};

