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
    void RenderText();

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

    const string ASSET_PATH = "Assets/karisozai/"; // �摜�t�H���_�̃p�X

    void LoadCSV(const string& fileName);
    void LoadImages();
    void UnloadImages();
    void CreateTextFont();
};
