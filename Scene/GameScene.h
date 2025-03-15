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

	bool Initialize() override; // ������
	void Update() override; // �X�V
	void Render() override; // �`��

private:

	void UIHide();
	bool isRenderUI = true;
	int lastClickTime; // �Ō�ɃN���b�N���ꂽ����
	const int clickInterval = 500;

	shared_ptr<UI>p_UI = nullptr;
	shared_ptr<Text>p_Text = nullptr;
};