#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

void printTextFile(string path)
{
    fstream file(path);
    string line;
    while (!file.eof())
    {
        getline(file, line);
        cout << line << "\n";
    }
}

void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}

void loadGame()
{
    ShowConsoleCursor(false);

    cout << "\n\t\t\t\t\t\t\t\tLoading." << flush;
    for (int i = 0; i < 5; i++)
    {
        cout << '.' << flush;
        Sleep(500);
        cout << '.' << flush;
        Sleep(500);
        cout << "\b\b  \b\b" << flush;
        Sleep(500);
    }
    cout << "\b\b\b\b\b\b\b\b\b\b          ";
    ShowConsoleCursor(true);
}

void mainMenu()
{
    cout << "\n\t\t\t\t\t\t\t\tSELECT MODE\n\n";
    string modes[5] =  {"New Game", "Scoreboard", "Help", "About", "Exit"};
    for (int i = 0; i < 5; i++) cout << "\t\t\t\t\t\t\t\t[" + to_string(i+1) + "] " + modes[i] << endl;
}