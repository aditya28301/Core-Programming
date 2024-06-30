#include <Windows.h> 

#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "kernel32.lib")

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam); 

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    static TCHAR szClassName[] = TEXT("The Standarad Window");
    static TCHAR szWndTitle [] = TEXT("Win32 Perfect ScrollBar Application");

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
        WS_OVERLAPPED | WS_CAPTION | WS_THICKFRAME | WS_SYSMENU | WS_MINIMIZEBOX| WS_MAXIMIZEBOX
        | WS_VSCROLL | WS_HSCROLL,
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
            TEXT("Failed to CreateWindow"),
            TEXT("CreateWindowEx"),
            MB_ICONERROR | MB_TOPMOST
        );
        ExitProcess(EXIT_FAILURE);
    }

    ShowWindow(hwnd, nShowCmd);
    UpdateWindow(hwnd);

    while(GetMessage(&msg, NULL, 0 , 0)){
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return((int)msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){

    #define NR_ROW 60
    #define NR_COL 60
    #define MAX_CHARS 20

    static TCHAR szFormattedString[] = TEXT("ROW=%d, COL=%d");
    static TCHAR szOutputString[MAX_CHARS];

    static cxChar;
    static cyChar;
    static cxScreen;
    static cyScreen;

    int iVScrollPosition;
    int iHScrollPosition;
    int iPaintBeginVertical;
    int iPaintEndVertical;
    int iRowCount;
    int iColCount;
    int iLenght; 

    SCROLLINFO si;
    HDC hdc = NULL;
    TEXTMETRIC tm;
    PAINTSTRUCT ps;

    switch(uMsg){

        case WM_CREATE:
            hdc = GetDC(hwnd);
            GetTextMetrics(hdc, &tm);
            ReleaseDC(hwnd, hdc);

            cxChar = tm.tmAveCharWidth;
            cyChar = tm.tmHeight + tm.tmExternalLeading;
        break;

        case WM_PAINT:
            hdc = BeginPaint(hwnd, &ps);
            
            si.cbSize = sizeof(SCROLLINFO);
            si.fMask = SIF_POS;
            GetScrollInfo(hwnd, SB_VERT, &si);
            iVScrollPosition = si.nPos;
            GetScrollInfo(hwnd, SB_HORZ, &si);
            iHScrollPosition = si.nPos;

            iPaintBeginVertical = max(0, iVScrollPosition + ps.rcPaint.top / cyChar);
            iPaintEndVertical = min(NR_ROW - 1, iVScrollPosition + ps.rcPaint.bottom / cyChar);

            for(iRowCount = iPaintBeginVertical;
                iRowCount <= iPaintEndVertical;
                ++iRowCount)
            {
                for(iColCount = 0; iColCount < NR_COL; ++iColCount){
                    iLenght = wsprintf(szOutputString, szFormattedString, iRowCount, iColCount);
                    TextOut(

                            hdc,
                            (MAX_CHARS * iColCount - iHScrollPosition) * cxChar,
                            (iRowCount - iVScrollPosition) * cyChar,
                            szOutputString,
                            iLenght
                    );
                }
            }
            EndPaint(hwnd, &ps);
        break;

        case WM_SIZE:
            cxScreen = LOWORD(lParam);
            cyScreen = HIWORD(lParam);

            si.cbSize = sizeof(si);
            si.fMask = SIF_RANGE | SIF_PAGE;
            si.nMin = 0;
            si.nMax = NR_ROW - 1;
            si.nPage = cyScreen / cyChar;
            SetScrollInfo(hwnd, SB_VERT, &si, TRUE);

            si.cbSize = sizeof(si);
            si.fMask = SIF_RANGE | SIF_PAGE;
            si.nMin = 0;
            si.nMax = (NR_COL * MAX_CHARS) - (cxScreen / cxChar);
            si.nPage = 2 + cxScreen / (MAX_CHARS * cxChar);
            SetScrollInfo(hwnd, SB_HORZ, &si, TRUE);
        break;

        case WM_VSCROLL:
            si.cbSize = sizeof(si);
            si.fMask = SIF_ALL;
            GetScrollInfo(hwnd, SB_VERT, &si);
            iVScrollPosition = si.nPos;

            switch(LOWORD(wParam)){
                case SB_LINEUP:
                    si.nPos -= 1;
                break;

                case SB_PAGEUP:
                    si.nPos -= si.nPage;
                break;

                case SB_LINEDOWN:
                    si.nPos += 1;
                break;

                case SB_PAGEDOWN:
                    si.nPos += 1;
                break;

                case SB_TOP:
                    si.nPos = si.nMin;
                break;

                case SB_BOTTOM:
                    si.nPos = si.nMax;
                break;

                case SB_THUMBPOSITION:
                    si.nPos = si.nTrackPos;
                break;
            }

            si.cbSize = sizeof(si);
            si.fMask = SIF_POS;
            SetScrollInfo(hwnd, SB_VERT, &si, TRUE);
            GetScrollInfo(hwnd, SB_VERT, &si);
            if(iVScrollPosition != si.nPos){
                ScrollWindow(hwnd, 0, (iVScrollPosition - si.nPos) * cyChar, NULL, NULL);
                UpdateWindow(hwnd);
            }
        break;

        case WM_HSCROLL:
            si.cbSize = sizeof(SCROLLINFO);
            si.fMask = SIF_ALL;
            GetScrollInfo(hwnd, SB_HORZ, &si);
            iHScrollPosition = si.nPos;

            switch(LOWORD(wParam)){

                case SB_LINELEFT:
                    si.nPos -= 1;
                break;

                case SB_PAGELEFT:
                    si.nPos -= si.nPage;
                break;

                case SB_LINERIGHT:
                    si.nPos += 1;
                break;

                case SB_PAGERIGHT:
                    si.nPos += si.nPage;
                break;

                case SB_THUMBPOSITION:
                    si.nPos = si.nTrackPos;
                break;
            }
                si.cbSize = sizeof(SCROLLINFO);
                si.fMask = SIF_POS;
                SetScrollInfo(hwnd, SB_HORZ, &si, TRUE);
                GetScrollInfo(hwnd, SB_HORZ, &si);
                if(iHScrollPosition != si.nPos){
                    ScrollWindow(hwnd, (iHScrollPosition - si.nPos) * cxChar,0,  NULL, NULL); 
                    UpdateWindow(hwnd);
                }
        break;

        case WM_DESTROY:
            PostQuitMessage(EXIT_SUCCESS);
        break;
    }
        return(DefWindowProc(hwnd, uMsg, wParam, lParam));
}