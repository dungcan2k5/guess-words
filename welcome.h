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