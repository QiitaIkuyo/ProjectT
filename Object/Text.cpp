#include "Text.h"
#include "DxLib.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

Text::Text(const string& csvFileName) : currentLine(0)
{
    LoadCSV(csvFileName);
}

void Text::LoadCSV(const string& fileName) 
{

    ifstream file(fileName);
    string line;

    if (!file.is_open()) 
    {
        cerr << "ファイルを開くことができませんでした: " << fileName << std::endl;
        return;
    }

    while (getline(file, line)) 
    {

        vector<string> row;
        stringstream ss(line);
        string cell;

        while (getline(ss, cell, ',')) 
        {
            row.push_back(cell);
        }

        csvData.push_back(row);
    }

    file.close();

}

void Text::Update()
{

    if (CheckHitKey(KEY_INPUT_RETURN) == 1) 
    {   
        currentLine++;

        if (currentLine >= csvData.size()) 
        {
            currentLine = 0; // 最後の行に達したら最初に戻る
        }
    }

}

void Text::Render() const
{

    if (currentLine < csvData.size()) 
    {
        const auto& row = csvData[currentLine];

        int y = 50; // Y座標の初期値

        for (const auto& cell : row) 
        {

            DrawString(50, y, cell.c_str(), GetColor(255, 255, 255));
            
            y += 20; // 行ごとにY座標を調整

        }
    }
}