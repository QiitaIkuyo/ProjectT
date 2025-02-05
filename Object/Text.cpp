#include "Text.h"
#include "DxLib.h"
#include <fstream>
#include <sstream>
#include <iostream>

Text::Text(const std::string& csvFileName) : currentLine(0), backgroundImageHandle(-1), characterImageHandle(-1), fontSize(50), fontHandle(-1), updateInterval(1000)
{
    LoadCSV(csvFileName);
    LoadImages();
    lastUpdateTime = std::chrono::steady_clock::now(); // 初期化時の時間を記録
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
        std::cerr << "ファイルを開くことができませんでした: " << fileName << std::endl;
        return;
    }

    std::getline(file, line); // ヘッダーをスキップ

    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        SceneData data;
        std::string charImages, charNames;

        std::getline(ss, data.backgroundImage, ',');
        std::getline(ss, charImages, ',');
        std::getline(ss, charNames, ',');
        std::getline(ss, data.text, ',');

        // カンマ区切りで複数のキャラクターを格納
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
            std::cerr << "背景画像の読み込みに失敗: " << csvData[currentLine].backgroundImage << std::endl;
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
                std::cerr << "キャラクター画像の読み込みに失敗: " << img << std::endl;
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
            currentLine = 0; // 最後の行に達したら最初に戻る
        }
        UnloadImages();
        LoadImages();
        lastUpdateTime = now; // 最後にシナリオを進めた時間を更新
    }
}

void Text::Render() const
{

    if (csvData.empty())
    {
        DrawString(50, 50, "シナリオデータがありません", GetColor(255, 255, 255));
        return;
    }

    if (backgroundImageHandle != -1)
    {
        DrawGraph(0, 0, backgroundImageHandle, TRUE);
    }

    // キャラクター画像を横並びに描画
    int x = 100;
    for (size_t i = 0; i < characterImageHandles.size(); ++i)
    {
        if (characterImageHandles[i] != -1)
        {
            DrawGraph(x, 200, characterImageHandles[i], TRUE);
        }
        x += 200; // キャラごとに位置をずらす
    }
}

void Text::RenderText()
{
	if (csvData.empty())
	{
		DrawString(50, 50, "シナリオデータがありません", GetColor(255, 255, 255));
		return;
	}

	// 名前とセリフの描画
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

	fontHandle = CreateFontToHandle("ＭＳ ゴシック", fontSize, 3, DX_FONTTYPE_ANTIALIASING_EDGE, -1, -1);
	if (fontHandle == -1)
	{
		std::cerr << "フォントの作成に失敗" << std::endl;
	}
}