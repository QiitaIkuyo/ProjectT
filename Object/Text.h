#pragma once

#include <string>
#include <vector>

using namespace std;

class Text {

public:

    Text(const string& csvFileName);
    void Update();
    void Render() const;

private:

    vector<vector<string>> csvData;
    size_t currentLine;
    void LoadCSV(const string& fileName);
};
