#pragma once

#include "DxLib.h"

class Mouse 
{
public:

    static void GetMousePosition(int& x, int& y) {
        GetMousePoint(&x, &y);
    }

    static bool IsLeftButtonPressed() {
        return (GetMouseInput() & MOUSE_INPUT_LEFT) != 0;
    }

    static bool IsRightButtonPressed() {
        return (GetMouseInput() & MOUSE_INPUT_RIGHT) != 0;
    }

};