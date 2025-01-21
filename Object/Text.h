#pragma once

#include "DxLib.h"
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

// CSVファイルを読み取る関数
vector<vector<string>> ReadCSV(const string& fileName)
{
    vector<vector<string>> data;
    ifstream file(fileName);
    string line;

    while (getline(file, line))
    {
        vector<string> row;
        stringstream ss(line);
        string cell;

        while (getline(ss, cell, ','))
        {
            row.push_back(cell);
        }

        data.push_back(row);
    }

    file.close();
    return data;
}

// CSVデータから、Textを描画する関数
void RenderCSV(const vector<vector<string>>& csvData) {
    int y = 0; // Y座標の初期値

    for (const auto& row : csvData)
    {
        if (row.size() < 3) continue; // 不正な行をスキップ

        string characterName = row[0];
        string imagePath = row[1];
        string message = row[2];

        // キャラクターの名前を表示
        DrawString(50, y, characterName.c_str(), GetColor(255, 255, 255));
        y += 20;

        // キャラクターの画像を表示
        int imageHandle = LoadGraph(imagePath.c_str());
        if (imageHandle != -1) {
            DrawGraph(50, y, imageHandle, TRUE);
            y += 100; // 画像の高さ分Y座標を調整
        }

        // メッセージを表示
        DrawString(50, y, message.c_str(), GetColor(255, 255, 255));
        y += 40; // メッセージの高さ分Y座標を調整
    }
}

// CSVデータを読み込む関数
void CSVPathAssign(const string& fileName)
{
    // CSVファイルを読み込む
    vector<vector<string>> csvData = ReadCSV(fileName);

    // CSVデータを描画
    RenderCSV(csvData);
}