#include <Windows.h> 

#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "kernel32.lib")

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wPram, LPARAM lParam); 

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    static TCHAR szClassName[] = TEXT("The Standard Window"); 
    static TCHAR szWindowName[] = TEXT("TEXTOUT REPEAT"); 

    HWND hwnd = NULL; 

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
    wnd.hInstance = hInstance; 
    wnd.lpfnWndProc = WndProc; 
    wnd.lpszClassName = szClassName; 
    wnd.lpszMenuName = NULL; 
    wnd.style = CS_HREDRAW | CS_VREDRAW; 

    if(!RegisterClassEx(&wnd))
    {
        MessageBox(
            (HWND)NULL, 
            TEXT("Failed to register a window class"), 
            TEXT("RegisterClassEx"), 
            MB_ICONERROR | MB_TOPMOST
        ); 

        ExitProcess(EXIT_FAILURE); 
    }

    hwnd = CreateWindowEx(
        WS_EX_APPWINDOW, 
        szClassName, 
        szWindowName, 
        WS_OVERLAPPED | WS_CAPTION | WS_THICKFRAME | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | 
        WS_VSCROLL | WS_HSCROLL, 
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
        MessageBox(
            (HWND)NULL, 
            TEXT("Failed to create a window"), 
            TEXT("CreateWindowEx"), 
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
    #define NR_ROWS     64 
    #define NR_COLS     8 
    #define MAX_CHARS   48 

    static int cxScreen, cyScreen; 
    static int cxChar, cyChar; 
    static int iVScrollPosition, iHScrollPosition; 
    static TCHAR szFormatMessage[] = TEXT("Row Number = %d, Column Number = %d"); 
    static TCHAR szOutputMessage[MAX_CHARS]; 
    
    int iLength, iRowCounter, iColumnCounter; 

    HDC hdc = NULL; 

    PAINTSTRUCT ps;
    TEXTMETRIC tm; 

    switch(uMsg)
    {
        case WM_CREATE: 
            hdc = GetDC(hwnd); 
            GetTextMetrics(hdc, &tm); 
            ReleaseDC(hwnd, hdc);
            cxChar = tm.tmAveCharWidth; 
            cyChar = tm.tmHeight + tm.tmExternalLeading; 

            SetScrollRange(hwnd, SB_VERT, 0, NR_ROWS-1, FALSE); 
            SetScrollPos(hwnd, SB_VERT, iVScrollPosition, TRUE); 

            SetScrollRange(hwnd, SB_HORZ, 0, NR_COLS * MAX_CHARS * cxChar - 1, FALSE); 
            SetScrollPos(hwnd, SB_HORZ, iHScrollPosition, TRUE); 

            break; 

        case WM_SIZE: 
            cxScreen = LOWORD(lParam); 
            cyScreen = HIWORD(lParam); 
            break; 

        case WM_PAINT: 
            hdc = BeginPaint(hwnd, &ps); 
            for(iRowCounter = 0; iRowCounter < NR_ROWS; ++iRowCounter)
            {
                for(iColumnCounter = 0; iColumnCounter < NR_COLS; ++iColumnCounter)
                {
                    ZeroMemory(szOutputMessage, MAX_CHARS); 
                    iLength = wsprintf(szOutputMessage, szFormatMessage, iRowCounter, iColumnCounter); 
                    TextOut(
                        hdc, 
                        (iColumnCounter * MAX_CHARS - iHScrollPosition) * cxChar, 
                        (iRowCounter - iVScrollPosition) * cyChar, 
                        szOutputMessage, 
                        iLength
                    ); 
                }
            }
            EndPaint(hwnd, &ps); 
            break; 

        case WM_VSCROLL: 
            switch(LOWORD(wParam))
            {
                case SB_LINEUP: 
                    iVScrollPosition -= 1; 
                    break; 

                case SB_PAGEUP: 
                    iVScrollPosition -= cyScreen/cyChar; 
                    break; 

                case SB_LINEDOWN: 
                    iVScrollPosition += 1; 
                    break; 

                case SB_PAGEDOWN: 
                    iVScrollPosition += cyScreen / cyChar; 
                    break; 

                case SB_THUMBPOSITION: 
                    iVScrollPosition = HIWORD(wParam);
                    break; 
            }

            iVScrollPosition = max(0, min(iVScrollPosition, NR_ROWS-1));
            if(iVScrollPosition != GetScrollPos(hwnd, SB_VERT))
            {
                SetScrollPos(hwnd, SB_VERT, iVScrollPosition, FALSE); 
                InvalidateRect(hwnd, NULL, TRUE); 
            }

            break; 

        case WM_HSCROLL: 
            switch(LOWORD(wParam))
            {
                case SB_LINELEFT: 
                    iHScrollPosition -= 1; 
                    break; 

                case SB_PAGELEFT: 
                    iHScrollPosition -= cxScreen / cxChar; 
                    break; 

                case SB_LINERIGHT: 
                    iHScrollPosition += 1; 
                    break; 
                
                case SB_PAGERIGHT: 
                    iHScrollPosition += cxScreen / cxChar; 
                    break; 

                case SB_THUMBPOSITION: 
                    iHScrollPosition = HIWORD(wParam); 
                    break; 
            }

            iHScrollPosition = max(0, min(iHScrollPosition, MAX_CHARS * NR_COLS * cxChar-1)); 
            if(iHScrollPosition != GetScrollPos(hwnd, SB_HORZ))
            {
                SetScrollPos(hwnd, SB_HORZ, iHScrollPosition, FALSE); 
                InvalidateRect(hwnd, NULL, TRUE); 
            }

            break; 

        case WM_DESTROY: 
            PostQuitMessage(EXIT_SUCCESS); 
            break; 
    }

    return (DefWindowProc(hwnd, uMsg, wParam, lParam)); 
}