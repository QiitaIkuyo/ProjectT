#pragma once

#include "BaseScene.h"
#include "TitleScene.h"
#include "GameScene.h"
#include "SettingScene.h"
#include <memory>

using namespace std;

// �V�[����
enum Scene
{
	Title,			// TitleScene
	Game,		// GameScene
	Setting,	// SettingScene
};


// ���̃N���X�ŃV�[���J�ڂ��Ǘ�
class SceneManager
{
public:
	
	static bool Initialize(); // ������
	static void Update(); // �X�V
	static void Render(); // �`��

	// �����̃V�[���ɑJ��
	static void TransitionScene(Scene agoScene);

private:

	static std::unique_ptr<BaseScene>sceneName;
};