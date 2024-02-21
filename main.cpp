#include <conio.h>

#include "welcome.h"
#include "game.h"

using namespace std;

void configWindow()
{
    SetConsoleTitleW(L"Guess Words");
    HWND console = GetConsoleWindow();

    //MoveWindow(window_handle, x, y, width, height, redraw_window);
    MoveWindow(console, 100, 100, 1150, 600, TRUE);
}

void chooseMode()
{
    cout << "\n\t\tMode Selection: ";
    int mode = getch();

    switch (mode)
    {
    case '1':
        newGame();
        break;
    case '2':
        print_text_file("Scoreboard.txt");
        break;
    case '3':
        system("HuongDan.txt");
        break;
    case '4':
        system("ThongTin.txt");
        break;
    case '5':
        cout << "\n\n\tThanks! See you!!!";
        Sleep(1500);
        system("cls");
        exit(0);
        break;
    default:
        break;
    }
}

int main()
{
    configWindow();
    print_text_file("Logo.txt");
    // loadGame();
    mainMenu();
    while (true) chooseMode();
    return 0;
}
