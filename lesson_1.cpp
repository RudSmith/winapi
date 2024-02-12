#include <windows.h>

// menu handler
HMENU hMenu;

// функция обработки событий с окна
LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);
// функция добавления менюшек
void AddMenus(HWND hWindow);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    // Создаём класс окна
    WNDCLASSW window = { 0 };
    window.hbrBackground = (HBRUSH)COLOR_WINDOW; // Фон
    window.hCursor = LoadCursor(NULL, IDC_ARROW); // Курсор
    window.hInstance = hInstance; // instance того, кто создаёт окно (наша программа)
    window.lpszClassName = L"inshallaWindow"; // имя класса
    window.lpfnWndProc = WindowProcedure; // функция обработки сообщений

    // Регистрируем класс окна
    if(!RegisterClassW(&window))
        return -1;

    // Создаём окно
    CreateWindowW(L"inshallaWindow", L"peepeePoopoo", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 
        200, 200, 300, 400, NULL, NULL, NULL, NULL);

    // Структура сообщения
    MSG message = { 0 };

    // Цикл обработки сообщений
    while(GetMessage(&message, NULL, NULL, NULL))
    {
        TranslateMessage(&message);
        DispatchMessage(&message);
    }

    return 0;
}

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) // WPARAM - айди объекта, который послал сообщение
{
    // Обрабатываем сообщения тут
    switch (msg)
    {
    case WM_CREATE:
        AddMenus(hWnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    case WM_COMMAND:
        // WPARAM - айди того, кто вызывает сообщение
        switch (wp)
        {
        case 1: // 1 - менюшка
            MessageBox(hWnd, L"Developed by DCP.X_Y in 2024", L"About", MB_OK);
            break;
        default:
            break;
        }

        break;
    default:
        return DefWindowProcW(hWnd, msg, wp, lp);
        break;
    }
}

void AddMenus(HWND hWindow)
{
    hMenu = CreateMenu(); // Создаём менюшку
    AppendMenu(hMenu, MF_STRING, 1, L"About"); // Добавляем новый элемент, всё что на MF_ - элементы меню

    SetMenu(hWindow, hMenu); // Задаём менюшку для окна
}