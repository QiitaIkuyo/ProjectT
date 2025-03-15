#pragma once
#pragma once

#include "DxLib.h"
#include <memory>

using namespace std;

class UI
{
public:
	UI() {};
	~UI() {  };

	// ‰Šú‰»EXV‚È‚Ç
	void Initialize();
	void Update();
	void Render();

private:
	int messageWindow;
	int magnifyingGlass;
};

