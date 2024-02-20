#include <iostream>
#include <fstream>

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

void mainMenu()
{
    cout << "\n\t\t\t\t\t\t\t\tSELECT MODE\n\n";
    string modes[5] =  {"New Game", "Scoreboard", "Help", "About", "Exit"};
    for (int i = 0; i < 5; i++) cout << "\t\t\t\t\t\t\t\t[" + to_string(i+1) + "] " + modes[i] << endl;
}