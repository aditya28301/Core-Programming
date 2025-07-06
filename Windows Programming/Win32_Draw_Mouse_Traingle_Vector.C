#include <Windows.h>
#include <windowsx.h>

#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "kernel32.lib")

#define MAX_CHARS 32

typedef long long ssize_t;
HWND ghwnd;

typedef struct tagPointerVect{
    POINT* pPoint;
    ssize_t N;
} POINTVECT, *PPOINTVECT;

PPOINTVECT CreateVector(VOID);
VOID PushBack(PPOINTVECT, ssize_t, ssize_t);
VOID DestroyVect(PPOINTVECT);

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

    ghwnd = hwnd;

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
    #define NR_POINT_ARRAY 4
    #define NR_TRIANGLE_POINT 3

    static int cxScreen, cyScreen;      
    static int cxChar;
    static int cyChar;

    int rowCounter;
    int colCounter;

    static int cnt = 0;
    static TCHAR szSizeBuffer[MAX_CHARS];
    BOOL bvar;

    static PPOINTVECT pPointVect = NULL;
    ssize_t x;
    ssize_t y;

    int iLength;
    switch(uMsg)
    {
        HDC hdc = NULL;
        PAINTSTRUCT ps;
        TEXTMETRIC tm;

         case WM_CREATE:

            pPointVect = CreateVector();

            hdc= GetDC(hwnd);
            GetTextMetrics(hdc, &tm);
            ReleaseDC(hwnd, hdc);

            cxChar = tm.tmAveCharWidth;
            cyChar = tm.tmHeight + tm.tmExternalLeading;


        break;

        case WM_PAINT:
            hdc = BeginPaint(hwnd, &ps);

            for(int iRowCount = 0; iRowCount < pPointVect->N; iRowCount = iRowCount + NR_POINT_ARRAY)
                Polyline(hdc, &pPointVect->pPoint[iRowCount], NR_POINT_ARRAY);

            EndPaint(hwnd, &ps);
        break;

        case WM_SIZE:
            cxScreen = LOWORD(lParam);
            cyScreen = HIWORD(lParam);
            break;

        case WM_LBUTTONDOWN:
            bvar = FALSE;
            x = GET_X_LPARAM(lParam);
            y = GET_Y_LPARAM(lParam);

            PushBack(pPointVect, x, y); 

            if(cnt == 2){
                bvar = TRUE;

                PushBack(
                pPointVect,
                pPointVect->pPoint[pPointVect-> N - 3].x,
                pPointVect->pPoint[pPointVect->N - 3].y);
            }
            cnt = (cnt + 1) % NR_TRIANGLE_POINT;

            if(bvar == TRUE){
                InvalidateRect(hwnd, NULL, TRUE);
            }
        break;

        case WM_DESTROY:
            DestroyVect(pPointVect);
            PostQuitMessage(EXIT_SUCCESS);
            break;

    }
    return (DefWindowProc(hwnd, uMsg, wParam, lParam));
}

PPOINTVECT CreateVector(VOID){
    PPOINTVECT pvec = NULL;

    pvec = (PPOINTVECT)malloc(sizeof(POINTVECT));
    if(pvec == NULL)
        DestroyWindow(ghwnd);
    pvec->pPoint = NULL;
    pvec->N = 0;
    return(pvec);
}

VOID PushBack(PPOINTVECT pPvect, ssize_t x, ssize_t y){
    ssize_t lNew_Required_Size = (pPvect->N + 1) * sizeof(POINT);

    pPvect->pPoint = (PPOINT)realloc(pPvect->pPoint, lNew_Required_Size); 
    if(pPvect->pPoint == NULL)
        DestroyWindow(ghwnd);

    pPvect->N += 1;
    pPvect->pPoint[pPvect->N - 1].x = x;
    pPvect->pPoint[pPvect->N - 1].y = y;
}

VOID DestroyVect(PPOINTVECT pPvect){
    free(pPvect->pPoint);
    free(pPvect);
}