#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

void print_text_file(string path)
{
    fstream file(path);
    string line;
    while (!file.eof())
    {
        getline(file, line);
        cout << line << "\n";
    }
}

void loadGame()
{
    char loadItems[] = {'|', '/', '-', '\\', '|', '/', '-', '\\'};
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << loadItems[i] << "\033[D";
            Sleep(50);
        }
        
    }
    
}

void mainMenu()
{
    cout << "\n\t\t\t\t\t\t\t\tSELECT MODE\n\n";
    string modes[5] =  {"New Game", "Scoreboard", "Help", "About", "Exit"};
    for (int i = 0; i < 5; i++) cout << "\t\t\t\t\t\t\t\t[" + to_string(i+1) + "] " + modes[i] << endl;
}