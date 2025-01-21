#pragma once

#include "DxLib.h"
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

// CSVファイルを読み取る関数
vector<vector<string>> ReadCSV(const string& filename)
{
    vector<vector<string>> data;
    ifstream file(filename);
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

    return data;
}

// Textの描画サイズなどを調整する関数
void RenderCSV(const vector<vector<string>>& csvData) {
    int y = 0; // Y座標の初期値

    for (const auto& row : csvData)
    {
        string line;
        for (const auto& cell : row)
        {
            line += cell + " "; // セルをスペースで区切る
        }

        // 1行ごとに表示
        DrawString(50, y, line.c_str(), GetColor(255, 255, 255));
        y += 20; // 次の行に進む
    }
}

// CSVデータから、Textを描画する関数
void RenderText()
{
    // CSVファイルを読み込む
    vector<vector<string>> csvData = ReadCSV("data.csv");

    while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
    {
        // CSVデータを描画
        RenderCSV(csvData);
    }
}