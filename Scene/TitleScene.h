#pragma once
#include "DxLib.h"
#include "../Scene/BaseScene.h"

using namespace std;

class TitleScene : public BaseScene
{
public:

	TitleScene() {};
	~TitleScene() {};

	bool Initialize() override { return true; }; // ������
	void Update()override {}; // �X�V
	void Render()override {}; // �`��

private:


};