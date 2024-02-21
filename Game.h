#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <vector>
#include <map>
#include <time.h>
using namespace std;
void random(int mang[])
{
    srand((int)time(0));
    int r, minN = 0, maxN = 14;
    int cnt = 15;
    map<int, bool> vis;
    for (int i = 0; i < cnt; ++i)
    {
        // Random cho toi khi r chua co trong map vis
        do
        {
            r = minN + rand() % (maxN + 1 - minN);
            mang[i] = r;
        } while (vis.find(r) != vis.end());
        vis[r] = true;
    }
}
void in_tu(char chr[], int so_luong)
{
    cout << "\t\t\t\t\t\t\t\t";
    for (int i = 0; i < so_luong; i++)
    {
        cout << chr[i] << " ";
    }
    cout << endl;
}
void check_player_mang(int &i, int player_mang[], int so_luong)
{
    if (player_mang[i] == 0)
    {
        i++;
    }
    if (i > so_luong - 1)
        i == 0;
}
void play(string data, string player[], int player_mang[], int n)
{
    int so_luong = data.size();
    int length = so_luong;
    char tu[so_luong];
    char dap_an[so_luong];
    // int number_player = player.lenght();
    for (int i = 0; i < so_luong; i++)
    {
        dap_an[i] = '_';
    }

    cout << "\t\t\t\t\t\t\t\tNumber of words : " << so_luong << "\n\n"; // In ra số lượng chữ của từ
    in_tu(dap_an, length);
    for (int i = 0; i < so_luong; i++)
        tu[i] = data[i];

    int cnt[27] = {0};
    for (int i = 0; i < so_luong; i++)
        cnt[data[i] - 65]++; // Đếm số lượng các chữ cái xuất hiện của từ
    while (so_luong)
    {
        for (int i = 0; i < so_luong + 1; i++)
        {
            if (i >= so_luong - 1)
                i = 0;
            // if (i >= so_luong - 1 || player_mang[i] == 0) check_player_mang(i, player_mang, so_luong);
            // if (player_mang[i] == 0) i++;
            cout << "Please " << player[i] << " choose letter\n";
            char chu; // Từ dự đoán của người chơi
            cin >> chu;
            chu = toupper(chu);

            for (int i = 0; i < length; i++)
            {
                if (chu == data[i])
                {
                    dap_an[i] = chu;
                }
            }

            if (cnt[chu - 65] != 0)
            {
                cout << "Have " << cnt[chu - 65] << " letter " << chu << "\n"; // in ra số lần xuất hiện của từ của ki tự nhập vào
                in_tu(dap_an, length);
                cout << player[i] << " have " << player_mang[i] << " heart\n"; // in ra số mạng còn lại
                so_luong -= cnt[chu - 65];
            }
            else
            {
                player_mang[i]--;
                cout << "Don't have " << chu << " letter.\n";
                cout << player[i] << " have " << player_mang[i] << " heart\n\n"; // in ra số mạng còn lại
            }
        }
    }
}

void inputQuestion(string file, string player[], int player_mang[], int n)
{
    fstream fin(file);
    string data;
    vector<string> word(15);
    // int i = -1;
    int mang[15] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    random(mang);
    while (fin.is_open())
    {
        for (int i = 0; i < 15; i++)
        {
            getline(fin, word[i]);
        }
        fin.close();
    }
    for (int i = 0; i < 15; i++)
    {
        data = word[mang[i]];
        play(data, player, player_mang, n);
    }
    // while (!fin.eof())
    // {
    //     // getline(fin,word[i++]);
    //     getline(fin, data);
    //     play(data, player, player_mang, n);
    // }
}

void newGame()
{
    // inputQuestion("BoCauHoi.txt");
    cout << "\n\tEnter the number of player: ";
    int n;
    cin >> n;
    cout << "\n";
    string player[n];
    int player_mang[n];
    for (int i = 0; i < n; i++)
    {
        cout << "\tInsert name of player " << i + 1 << ": ";
        string name;
        cin >> name;
        cout << "\n";
        player[i] = name;
        player_mang[i] = 6;
    }
    // Nhập số lượng người chơi , tên người chơi
    inputQuestion("BoCauHoi.txt", player, player_mang, n);
}
