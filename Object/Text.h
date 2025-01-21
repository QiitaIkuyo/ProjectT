#pragma once

#include "DxLib.h"
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

// CSV�t�@�C����ǂݎ��֐�
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

// CSV�f�[�^����AText��`�悷��֐�
void RenderCSV(const vector<vector<string>>& csvData) {
    int y = 0; // Y���W�̏����l

    for (const auto& row : csvData)
    {
        if (row.size() < 3) continue; // �s���ȍs���X�L�b�v

        string characterName = row[0];
        string imagePath = row[1];
        string message = row[2];

        // �L�����N�^�[�̖��O��\��
        DrawString(50, y, characterName.c_str(), GetColor(255, 255, 255));
        y += 20;

        // �L�����N�^�[�̉摜��\��
        int imageHandle = LoadGraph(imagePath.c_str());
        if (imageHandle != -1) {
            DrawGraph(50, y, imageHandle, TRUE);
            y += 100; // �摜�̍�����Y���W�𒲐�
        }

        // ���b�Z�[�W��\��
        DrawString(50, y, message.c_str(), GetColor(255, 255, 255));
        y += 40; // ���b�Z�[�W�̍�����Y���W�𒲐�
    }
}

// CSV�f�[�^��ǂݍ��ފ֐�
void CSVPathAssign(const string& fileName)
{
    // CSV�t�@�C����ǂݍ���
    vector<vector<string>> csvData = ReadCSV(fileName);

    // CSV�f�[�^��`��
    RenderCSV(csvData);
}