#include <Windows.h>

#pragma comment (lib, "gdi32.lib")
#pragma comment (lib, "user32.lib")
#pragma comment (lib, "kernel32.lib")

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    static TCHAR szClassName[] = TEXT("Standard Window Class");
    static TCHAR szWndTitle[] = TEXT("Win32 TextOut Screen resizing Dimension");

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
    wnd.style = CS_VREDRAW | CS_HREDRAW;

    if(!RegisterClassEx(&wnd)){
        MessageBox(
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

    if(hwnd == NULL){

        MessageBox(
            (HWND)NULL,
            TEXT("Failed to CreateWindowEx"),
            TEXT("CreateWindowEx"),
            MB_ICONERROR | MB_TOPMOST
        );
        ExitProcess(EXIT_FAILURE);
    }

    ShowWindow(hwnd, nShowCmd);
    UpdateWindow(hwnd);

    while(GetMessage(&msg, NULL, 0, 0)){
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return ((int)msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){

    #define MAX_CHARS 28

    static TCHAR szFormattedMessage[] = TEXT("HEIGHT = %d, WIDTH = %d");
    static TCHAR szOutPutMessage [MAX_CHARS];

    static int cxScreen;
    static int cyScreen;
    static int cxChar;
    static int cyChar;
    static oSwitch;

    int iLenght;
    int iRowCount;
    int iColCount;
    int wTextCol;
    int EndPaintHorizontal;
    int EndPaintVerticle;
    int cxClient;
    int cyClient;

    HDC hdc = NULL;
    PAINTSTRUCT ps;
    TEXTMETRIC tm;
    RECT rect;

    switch(uMsg){

    case WM_CREATE:
        hdc = GetDC(hwnd);
        GetTextMetrics(hdc, &tm);
        ReleaseDC(hwnd, hdc);

        cxChar = tm.tmAveCharWidth;
        cyChar = tm.tmHeight + tm.tmExternalLeading;
    break;

    case WM_LBUTTONDOWN:
        MessageBox(
            (HWND)NULL,
            szOutPutMessage,
            TEXT("Dimension"),
            MB_OK | MB_TOPMOST
        );

        oSwitch += 1;
        InvalidateRect(hwnd, NULL, TRUE);
    break;

    case WM_PAINT:
        hdc = BeginPaint(hwnd, &ps);

        if(oSwitch % 2 == 1)
        {
            for(iRowCount = 0; iRowCount < 64; iRowCount += 3){
                for(iColCount = 0; iColCount < 40; ++iColCount){
                    int xPos = iColCount * (MAX_CHARS * cxChar);
                    int yPos = iRowCount * cyChar;
                    iLenght = wsprintf(szOutPutMessage, szFormattedMessage, cxScreen, cyScreen);
                    TextOut(
                        hdc, 
                        xPos, 
                        yPos, 
                        szOutPutMessage, 
                        iLenght
                    );
                }
            }
        }
        else{

            SetTextAlign(hdc, TA_TOP | TA_CENTER);
            iLenght = wsprintf(szOutPutMessage, szFormattedMessage, cxScreen, cyScreen);
            TextOut(
                hdc, 
                cxScreen / 2, 
                cyScreen / 2, 
                szOutPutMessage, 
                iLenght
            );   
        }

        EndPaint(hwnd , &ps);    
    break;

    case WM_SIZE:
        cxScreen = LOWORD(lParam);
        cyScreen = HIWORD(lParam);
    break;

    case WM_DESTROY:
        PostQuitMessage(EXIT_FAILURE);
    break;
    }
    return (DefWindowProc(hwnd, uMsg, wParam, lParam));
}