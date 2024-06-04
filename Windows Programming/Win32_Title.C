#include <Windows.h>

#pragma comment (lib, "gdi32.lib")
#pragma comment (lib, "kernel32.lib")
#pragma comment (lib, "user32.lib")



LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    static TCHAR szClassName [] = TEXT("Standard Window Class");
    static TCHAR szWndTitle [] = TEXT("Win32 SDK Application");

    HWND hwnd;
    WNDCLASSEX wnd;
    MSG msg;

    ZeroMemory(&wnd, sizeof(WNDCLASSEX));
    ZeroMemory(&msg, sizeof(MSG));

    wnd.cbSize = sizeof(WNDCLASSEX);
    wnd.cbClsExtra =  0;
    wnd.cbWndExtra = 0;
    wnd.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wnd.hCursor = LoadCursor((HINSTANCE)NULL, IDC_ARROW);
    wnd.hIcon = LoadIcon((HINSTANCE)NULL, IDI_APPLICATION);
    wnd.hIconSm = LoadIcon((HINSTANCE)NULL, IDI_APPLICATION);
    wnd.lpszClassName = szClassName;
    wnd.lpszMenuName = NULL;
    wnd.lpfnWndProc = WndProc;
    wnd.style = CS_VREDRAW | CS_HREDRAW;

    if(!RegisterClassEx(&wnd))
    {
        MessageBox
        (
            (HWND)NULL,
            TEXT("Failed to Register the class"),
            TEXT("RegisterClassEx"),
            MB_ICONERROR | MB_TOPMOST
        );
        ExitProcess(EXIT_FAILURE);
    }

    hwnd = CreateWindowEx
            (
                WS_EX_APPWINDOW,
                szClassName,
                szWndTitle,
                WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX,
                CW_USEDEFAULT,
                CW_USEDEFAULT,
                CW_USEDEFAULT,
                CW_USEDEFAULT,
                (HWND)NULL,
                (HMENU)NULL,
                hInstance,
                (LPVOID)NULL
            );

        if(hwnd == NULL)
        {
            MessageBox
            (
                (HWND)NULL,
                TEXT("Failed to Create Window"),
                TEXT("CreateWindowClassEx"),
                MB_ICONERROR | MB_TOPMOST
            );
            ExitProcess(EXIT_FAILURE);
        }

        ShowWindow(hwnd, nShowCmd);
        UpdateWindow(hwnd);


        while(GetMessage(&msg, NULL, 0 , 0))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        return ((int)msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{

    static TCHAR szPrintMessage[] = TEXT("MSTC Core Program Academy Win32 SDK");
    static TCHAR szPrintMessage2[] = TEXT("Aditya Ashok Darekar");

    int iLenght = lstrlen(szPrintMessage);
    int iLenght2 = lstrlen(szPrintMessage2);

    static int cxScreen;
    static int cyScreen;

    static int cyChar;

    HDC hdc = NULL;
    PAINTSTRUCT ps;
    TEXTMETRIC tm;

    switch(uMsg)
    {
        case WM_CREATE:
            hdc = GetDC(hwnd);
            GetTextMetrics(hdc, &tm);
            ReleaseDC(hwnd, hdc);
            cyChar = tm.tmHeight + tm.tmExternalLeading;
        break;

        case WM_PAINT:
            hdc = BeginPaint(hwnd, &ps);
            SetTextAlign(hdc, TA_TOP | TA_CENTER);
            TextOut(hdc, cxScreen/2, cyScreen/2, szPrintMessage, iLenght);
            TextOut(hdc, cxScreen/2, cyScreen/2 + (cyChar * 2) , szPrintMessage2, iLenght2);
            EndPaint(hwnd, &ps);
        break;

        case WM_SIZE:
            cxScreen = LOWORD(lParam);
            cyScreen = HIWORD(lParam);
        break;

        case WM_DESTROY:
            PostQuitMessage(EXIT_SUCCESS);
        break;
    }
    return (DefWindowProc(hwnd, uMsg, wParam, lParam));
}