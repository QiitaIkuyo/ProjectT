#pragma once

#include "DxLib.h"
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

// CSV�t�@�C����ǂݎ��֐�
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

// Text�̕`��T�C�Y�Ȃǂ𒲐�����֐�
void RenderCSV(const vector<vector<string>>& csvData) {
    int y = 0; // Y���W�̏����l

    for (const auto& row : csvData)
    {
        string line;
        for (const auto& cell : row)
        {
            line += cell + " "; // �Z�����X�y�[�X�ŋ�؂�
        }

        // 1�s���Ƃɕ\��
        DrawString(50, y, line.c_str(), GetColor(255, 255, 255));
        y += 20; // ���̍s�ɐi��
    }
}

// CSV�f�[�^����AText��`�悷��֐�
void RenderText()
{
    // CSV�t�@�C����ǂݍ���
    vector<vector<string>> csvData = ReadCSV("data.csv");

    while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
    {
        // CSV�f�[�^��`��
        RenderCSV(csvData);
    }
}