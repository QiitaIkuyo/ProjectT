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

private:
    struct SceneData 
    {
        std::string backgroundImage;
        std::string characterImage;
        std::string characterName;
        std::string text;
    };

    std::vector<SceneData> csvData;
    size_t currentLine;
    int backgroundImageHandle;
    int characterImageHandle;

    void LoadCSV(const std::string& fileName);
    void LoadImages();
    void UnloadImages();
};
