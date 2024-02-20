#include <iostream>
#include <conio.h>

#include "welcome.h"

void chooseMode()
{
    int mode = getch();

    switch (mode)
    {
    case '1':
        // newGame();
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
        exit(0);
        break;
    default:
        break;
    }
}

int main()
{
    print_text_file("Logo.txt");
    mainMenu();
    chooseMode();
    return 0;
}
