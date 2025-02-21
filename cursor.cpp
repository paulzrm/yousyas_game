#ifndef __cursor_cpp_
#define __cursor_cpp_
#include "includes.h"
void hideCursor() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hOut, &cursorInfo);
    cursorInfo.bVisible = false; // 隐藏光标
    SetConsoleCursorInfo(hOut, &cursorInfo);
}

void showCursor() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hOut, &cursorInfo);
    cursorInfo.bVisible = true; // 显示光标
    SetConsoleCursorInfo(hOut, &cursorInfo);
}
#endif
