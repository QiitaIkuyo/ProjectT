#include "Text.h"
#include "DxLib.h"
#include <fstream>
#include <sstream>
#include <iostream>

Text::Text(const std::string& csvFileName) : currentLine(0), backgroundImageHandle(-1), characterImageHandle(-1)
{
    LoadCSV(csvFileName);
    LoadImages();
}

Text::~Text() 
{
    UnloadImages();
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

    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string cell;
        SceneData data;

        std::getline(ss, data.backgroundImage, ',');
        std::getline(ss, data.characterImage, ',');
        std::getline(ss, data.characterName, ',');
        std::getline(ss, data.text, ',');

        csvData.push_back(data);
    }

    file.close();
}

void Text::LoadImages()
{
    if (currentLine < csvData.size()) 
    {
        backgroundImageHandle = LoadGraph(csvData[currentLine].backgroundImage.c_str());
        characterImageHandle = LoadGraph(csvData[currentLine].characterImage.c_str());
    }
}

void Text::UnloadImages()
{
    if (backgroundImageHandle != -1) 
    {
        DeleteGraph(backgroundImageHandle);
    }
    if (characterImageHandle != -1) 
    {
        DeleteGraph(characterImageHandle);
    }
}

void Text::Update() 
{
    if (CheckHitKey(KEY_INPUT_RETURN) == 1) 
    {
        currentLine++;
        if (currentLine >= csvData.size()) 
        {
            currentLine = 0; // �Ō�̍s�ɒB������ŏ��ɖ߂�
        }
        UnloadImages();
        LoadImages();
    }
}

void Text::Render() const 
{
    if (backgroundImageHandle != -1) 
    {
        DrawGraph(0, 0, backgroundImageHandle, TRUE);
    }
    if (characterImageHandle != -1)
    {
        DrawGraph(100, 100, characterImageHandle, TRUE); // �L�����N�^�[�摜�̈ʒu�͓K�X����
    }
    DrawString(50, 50, csvData[currentLine].characterName.c_str(), GetColor(255, 255, 255));
    DrawString(50, 100, csvData[currentLine].text.c_str(), GetColor(255, 255, 255));
}
