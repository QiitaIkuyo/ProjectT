#pragma once
#pragma once

#include "DxLib.h"
#include <memory>

using namespace std;

class UI
{
public:
	UI() {};
	~UI() {};

	// 初期化・更新など
	void Initialize();
	void Update();
	void Render();

private:
	int messageWindow;

};

