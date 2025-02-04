#pragma once
#include <string>
#include <vector>

class Text
{
public:
    Text(const std::string& csvFileName);
    ~Text();
    void Update();
    void Render() const;
    void RenderText();

    void SetFontSize(int size);

private:
    struct SceneData 
    {
        std::string backgroundImage;
        std::vector<std::string> characterImages;
        std::vector<std::string> characterNames;
        std::string text;
    };


    std::vector<SceneData> csvData;
    size_t currentLine;
    int backgroundImageHandle;
    int characterImageHandle;
    std::vector<int> characterImageHandles;

    int fontSize;
    int fontHandle;

    const std::string ASSET_PATH = "Assets/karisozai/"; // 画像フォルダのパス

    void LoadCSV(const std::string& fileName);
    void LoadImages();
    void UnloadImages();
    void CreateTextFont();
};
