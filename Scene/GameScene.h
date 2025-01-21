#pragma once
#include "DxLib.h"
#include "../Scene/BaseScene.h"


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


};