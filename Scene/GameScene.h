#pragma once
#include <memory>

#include "DxLib.h"
#include "../Scene/BaseScene.h"
#include "../Object/UI.h"

using namespace std;

class GameScene : public BaseScene
{
public:

	GameScene() {};
	~GameScene() {};

	bool Initialize() override; // ‰Šú‰»
	void Update() override; // XV
	void Render() override; // •`‰æ

private:

	shared_ptr<UI>p_UI = nullptr;
};