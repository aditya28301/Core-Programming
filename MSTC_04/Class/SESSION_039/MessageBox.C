#include <Windows.h>
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "kernel32.lib")

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    MessageBox(
        NULL,
        TEXT("Hello Aditya Morning"),
        TEXT("WIN"),
        MB_OK | MB_TOPMOST
    );
    return (0);
}