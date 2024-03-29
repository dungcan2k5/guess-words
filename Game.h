#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <vector>
#include <map>
#include <time.h>
using namespace std;
char bang_tu[26];
void tạo_bang_tu(char x){
    int j = 0;
    for(char i = 'A'; i <= 'Z'; i++){
        bang_tu[j] = i;
        j++;
    }
}

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
    for(int i = 0; i < n; i++){
        player_mang[i] = 6;
    }
    bang_tu[26];
    for(int i = 0; i < 26; i++){
        bang_tu[i] = char(i + 65);
    }
    // int number_player = player.lenght();
    for (int i = 0; i < so_luong; i++)
    {
        dap_an[i] = '_';
    }

    cout << "\t\t\t\t\t\t\t\tNumber of words : " << so_luong << "\n\n"; // In ra số lượng chữ của từ
    in_tu(dap_an, length);
    for (int i = 0; i < so_luong - 1; i++)
        tu[i] = data[i];

    int cnt[27] = {0};
    for (int i = 0; i < so_luong; i++)
        cnt[data[i] - 65]++; // Đếm số lượng các chữ cái xuất hiện của từ
    
    int index = 0;
    while (so_luong)
    {
        for(int i = 0 ; i < 26; i++) cout << bang_tu[i] << " ";
        cout << "\n";
        // if (i >= so_luong - 1 || player_mang[i] == 0) check_player_mang(i, player_mang, so_luong);
        // if (player_mang[i] == 0) i++;
        if(player_mang[index] <= 0) continue;
        cout << "Please " << player[index] << " choose letter\n";
        char chu; // Từ dự đoán của người chơi
        cin >> chu;
        chu = toupper(chu);
        bang_tu[chu - 65] = '0';
        for (int j = 0; j < length; j++)
        {
            if (chu == data[j])
            {
                dap_an[j] = chu;
            }
        }

        if (cnt[chu - 65] != 0)
        {
            cout << "Have " << cnt[chu - 65] << " letter " << chu << "\n"; // in ra số lần xuất hiện của từ của ki tự nhập vào
            in_tu(dap_an, length);
            cout << player[index] << " have " << player_mang[index] << " heart\n"; // in ra số mạng còn lại
            so_luong -= cnt[chu - 65];
        }
        else{
            player_mang[index]--;
            cout << "Don't have " << chu << " letter.\n";
            cout << player[index] << " have " << player_mang[index] << " heart\n\n"; // in ra số mạng còn lại
            in_tu(dap_an, length);
            index++;
        }
        if (index == n) index = 0;
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
        //player_mang[i] = 6;
    }
    // Nhập số lượng người chơi , tên người chơi
    inputQuestion("BoCauHoi.txt", player, player_mang, n);
}
