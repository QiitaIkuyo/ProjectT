#pragma once
#include <string>
#include <vector>
#include <chrono>

using namespace std;

class Text
{
public:
    Text(const string& csvFileName);
    ~Text();
    void Update();
    void Render() const;
    void RenderText() const;

    void SetFontSize(int size);

private:
    struct SceneData 
    {
        string backgroundImage;
        vector<string> characterImages;
        vector<string> characterNames;
        string text;
    };


    std::vector<SceneData> csvData;
    size_t currentLine;
    int backgroundImageHandle;
    int characterImageHandle;
    vector<int> characterImageHandles;

    int fontSize;
    int fontHandle;

    chrono::steady_clock::time_point lastUpdateTime; // �Ō�ɃV�i���I��i�߂�����
    int updateInterval; // �V�i���I��i�߂�Ԋu

    size_t textIndex; // ���ݕ\������Ă���e�L�X�g�̃C���f�b�N�X
    std::chrono::steady_clock::time_point lastTextUpdateTime; // �Ō�Ƀe�L�X�g���X�V��������
    int textUpdateInterval; // �e�L�X�g�̍X�V�Ԋu�i�~���b�j

    const string ASSET_PATH = "Assets/karisozai/"; // �摜�t�H���_�̃p�X

    void LoadCSV(const string& fileName);
    void LoadImages();
    void UnloadImages();
    void CreateTextFont();
};
