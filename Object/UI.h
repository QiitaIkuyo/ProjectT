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

	// �������E�X�V�Ȃ�
	void Initialize();
	void Update();
	void Render();

private:
	int messageWindow;
	int magnifyingGlass;

	void UpdateAlphaValue(); // �A���t�@�l���X�V���郁���o�֐�
	int alphaValue; // �A���t�@�l��ێ����郁���o�ϐ�
	bool increasing; // �A���t�@�l�����������ǂ����������t���O
	float alphaTime; // �A���t�@�l���X�V����Ԋu

	void UpdateRotation(); // ��]�p�x���X�V���郁���o�֐�
	float rotationAngle; // ��]�p�x��ێ����郁���o�ϐ�
	float rogoInterbal; // ��]�p�x���X�V����Ԋu
	bool rotatingClockwise; // ���v���ɉ�]�����ǂ����������t���O
};

