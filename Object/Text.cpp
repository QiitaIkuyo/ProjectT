#include "Text.h"
#include "DxLib.h"
#include <fstream>
#include <sstream>
#include <iostream>

Text::Text(const std::string& csvFileName) : currentLine(0), backgroundImageHandle(-1), characterImageHandle(-1), fontSize(50), fontHandle(-1), updateInterval(1000)
{
    LoadCSV(csvFileName);
    LoadImages();
    lastUpdateTime = std::chrono::steady_clock::now(); // ���������̎��Ԃ��L�^
}

Text::~Text() 
{
    UnloadImages();
    if (fontHandle != -1)
    {
        DeleteFontToHandle(fontHandle);
    }
}

void Text::LoadCSV(const std::string& fileName)
{
    std::ifstream file(fileName);
    std::string line;

    if (!file.is_open())
    {
        std::cerr << "�t�@�C�����J�����Ƃ��ł��܂���ł���: " << fileName << std::endl;
        return;
    }

    std::getline(file, line); // �w�b�_�[���X�L�b�v

    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        SceneData data;
        std::string charImages, charNames;

        std::getline(ss, data.backgroundImage, ',');
        std::getline(ss, charImages, ',');
        std::getline(ss, charNames, ',');
        std::getline(ss, data.text, ',');

        // �J���}��؂�ŕ����̃L�����N�^�[���i�[
        std::stringstream imgStream(charImages);
        std::string img;
        while (std::getline(imgStream, img, '|')) {
            data.characterImages.push_back(img);
        }

        std::stringstream nameStream(charNames);
        std::string name;
        while (std::getline(nameStream, name, '|')) {
            data.characterNames.push_back(name);
        }

        csvData.push_back(data);
    }

    file.close();
}

void Text::LoadImages()
{
    if (currentLine < csvData.size())
    {
        backgroundImageHandle = LoadGraph((ASSET_PATH + csvData[currentLine].backgroundImage).c_str());
        if (backgroundImageHandle == -1)
        {
            std::cerr << "�w�i�摜�̓ǂݍ��݂Ɏ��s: " << csvData[currentLine].backgroundImage << std::endl;
        }

        for (int handle : characterImageHandles)
        {
            DeleteGraph(handle);
        }
        characterImageHandles.clear();

        for (const auto& img : csvData[currentLine].characterImages)
        {
            int handle = LoadGraph((ASSET_PATH + img).c_str());
            if (handle == -1)
            {
                std::cerr << "�L�����N�^�[�摜�̓ǂݍ��݂Ɏ��s: " << img << std::endl;
            }
            characterImageHandles.push_back(handle);
        }
    }
}



void Text::UnloadImages()
{
    if (backgroundImageHandle != -1)
    {
        DeleteGraph(backgroundImageHandle);
        backgroundImageHandle = -1;
    }

    for (int handle : characterImageHandles)
    {
        DeleteGraph(handle);
    }
    characterImageHandles.clear();
}


void Text::Update() {
    auto now = chrono::steady_clock::now();
    auto elapsed = chrono::duration_cast<chrono::milliseconds>(now - lastUpdateTime).count();

    if (CheckHitKey(KEY_INPUT_RETURN) == 1 && elapsed >= updateInterval) {
        currentLine++;
        if (currentLine >= csvData.size()) {
            currentLine = 0; // �Ō�̍s�ɒB������ŏ��ɖ߂�
        }
        UnloadImages();
        LoadImages();
        lastUpdateTime = now; // �Ō�ɃV�i���I��i�߂����Ԃ��X�V
    }
}

void Text::Render() const
{

    if (csvData.empty())
    {
        DrawString(50, 50, "�V�i���I�f�[�^������܂���", GetColor(255, 255, 255));
        return;
    }

    if (backgroundImageHandle != -1)
    {
        DrawGraph(0, 0, backgroundImageHandle, TRUE);
    }

    // �L�����N�^�[�摜�������тɕ`��
    int x = 100;
    for (size_t i = 0; i < characterImageHandles.size(); ++i)
    {
        if (characterImageHandles[i] != -1)
        {
            DrawGraph(x, 200, characterImageHandles[i], TRUE);
        }
        x += 200; // �L�������ƂɈʒu�����炷
    }
}

void Text::RenderText()
{
	if (csvData.empty())
	{
		DrawString(50, 50, "�V�i���I�f�[�^������܂���", GetColor(255, 255, 255));
		return;
	}

	// ���O�ƃZ���t�̕`��
	if (!csvData[currentLine].characterNames.empty())
	{
		DrawString(200, 780, csvData[currentLine].characterNames[0].c_str(), GetColor(255, 255, 255));
	}
	DrawString(150, 850, csvData[currentLine].text.c_str(), GetColor(255, 255, 255));
}

void Text::SetFontSize(int size)
{
    fontSize = size;
    CreateTextFont();
}

void Text::CreateTextFont()
{
    if (fontHandle != -1)
    {
        DeleteFontToHandle(fontHandle);
    }

	fontHandle = CreateFontToHandle("�l�r �S�V�b�N", fontSize, 3, DX_FONTTYPE_ANTIALIASING_EDGE, -1, -1);
	if (fontHandle == -1)
	{
		std::cerr << "�t�H���g�̍쐬�Ɏ��s" << std::endl;
	}
}