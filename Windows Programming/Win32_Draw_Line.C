#include <Windows.h>

#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "kernel32.lib")

#define MAX_CHARS 32

LRESULT CALLBACK WndProc(HWND hwndm, UINT uMSg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    static TCHAR szClassName[] = TEXT("The Standarad class Name");
    static TCHAR szWndTitle[] = TEXT("Win32 SDK Application");

    HWND hwnd;
    WNDCLASSEX wnd;
    MSG msg;

    ZeroMemory(&wnd, sizeof(WNDCLASSEX));
    ZeroMemory(&msg, sizeof(MSG));

    wnd.cbSize = sizeof(WNDCLASSEX);
    wnd.cbClsExtra = 0;
    wnd.cbWndExtra = 0;
    wnd.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wnd.hCursor = LoadCursor((HINSTANCE)NULL, IDC_ARROW);
    wnd.hIcon = LoadIcon((HINSTANCE)NULL, IDI_APPLICATION);
    wnd.hIconSm = LoadIcon((HINSTANCE)NULL, IDI_APPLICATION);
    wnd.lpszClassName = szClassName;
    wnd.lpszMenuName = NULL;
    wnd.lpfnWndProc = WndProc;
    wnd.hInstance = hInstance;
    wnd.style = CS_HREDRAW | CS_VREDRAW;

    if(!RegisterClassEx(&wnd))
    {
        MessageBox
        (
            (HWND)NULL,
            TEXT("Failed to Register Class"),
            TEXT("RegisterClassEx"),
            MB_ICONERROR | MB_TOPMOST
        );
        ExitProcess(EXIT_FAILURE);
    }

    hwnd = CreateWindowEx(
    WS_EX_APPWINDOW,
    szClassName,
    szWndTitle,
    WS_OVERLAPPED | WS_CAPTION | WS_THICKFRAME | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX,
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
            TEXT("Failed to create Window"),
            TEXT("CreateWindowClassEx"),
            MB_ICONERROR | MB_TOPMOST
        );
        ExitProcess(EXIT_FAILURE);
    }

    ShowWindow(hwnd, nShowCmd);
    UpdateWindow(hwnd);

    while(GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return ((int)msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    static int cxScreen, cyScreen;  
    static int cxChar;
    static int cyChar;

    int rowCounter;
    int colCounter;

    static TCHAR szSizeBuffer[MAX_CHARS];
    int iLength;
    switch(uMsg)
    {
        HDC hdc = NULL;
        PAINTSTRUCT ps;
        TEXTMETRIC tm;

         case WM_CREATE:
            hdc= GetDC(hwnd);
            GetTextMetrics(hdc, &tm);
            ReleaseDC(hwnd, hdc);

            cxChar = tm.tmAveCharWidth;
            cyChar = tm.tmHeight + tm.tmExternalLeading;

        break;

        case WM_PAINT:
            hdc = BeginPaint(hwnd, &ps);

            for(rowCounter = 1; (cxScreen - rowCounter * cxChar > cxScreen / 2) && (cyScreen - rowCounter * cxChar > cyScreen / 2) ; rowCounter++){
                MoveToEx(hdc, cxChar * rowCounter, cxChar * rowCounter, NULL);  
                LineTo(hdc, cxScreen - (rowCounter * cxChar) , rowCounter * cxChar);  

                MoveToEx(hdc, rowCounter * cxChar, rowCounter * cxChar, NULL);
                LineTo(hdc, rowCounter * cxChar, cyScreen - (rowCounter * cxChar));

                MoveToEx(hdc, rowCounter * cxChar, cyScreen - (rowCounter * cxChar), NULL);
                LineTo(hdc, cxScreen - (rowCounter * cxChar), cyScreen - (rowCounter * cxChar));

                MoveToEx(hdc, cxScreen - (rowCounter * cxChar), rowCounter * cxChar, NULL);
                LineTo(hdc, cxScreen - (rowCounter * cxChar), cyScreen - (rowCounter * cxChar));
            }

    

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
