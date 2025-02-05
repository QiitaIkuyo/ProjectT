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

    chrono::steady_clock::time_point lastUpdateTime; // 最後にシナリオを進めた時間
    int updateInterval; // シナリオを進める間隔

    const string ASSET_PATH = "Assets/karisozai/"; // 画像フォルダのパス

    void LoadCSV(const string& fileName);
    void LoadImages();
    void UnloadImages();
    void CreateTextFont();
};
