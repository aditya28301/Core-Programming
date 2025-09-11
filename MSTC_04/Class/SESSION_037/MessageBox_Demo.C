#include <windows.h>

#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "kernel32.lib")

int WINAPI WinMain(
        HINSTANCE hInstance,
        HINSTANCE hPrevInstance,
        LPSTR lpCmdLine,
        int nShowCmd
)
{
    MessageBox(
        NULL,
        TEXT("ADITYA DAREKAR MY FIRST GUI CODE"),
        TEXT("MSTC 04 SESSION 037"),
        MB_OK | MB_TOPMOST
    );
    
    return (0);
}