#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/* void in_tu(char tu[]){
     for(int i = 0; i < tu.size(); i++){
        cout << tu[i] << "_";
    }
 }
*/
void in_tu(char chr[], int so_luong)
{
    cout << "\t\t\t\t\t\t\t\t";
    for (int i = 0; i < so_luong; i++)
    {
        cout << chr[i] << " ";
    }

    cout << endl;
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
        for (int i = 0; i < so_luong; i++)
        {
            if (i >= so_luong-1)
                i = 0;
            cout << "Please " << player[i] << " choose letter\n";
            char chu; // Từ dự đoán của người chơi
            cin >> chu;
            chu = toupper(chu);

            for (int i = 0; i < length; i++){
                if (chu == data[i])
                {
                    dap_an[i] = chu;
                }
            }

            if (cnt[chu - 65] != 0){
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

void inputQuestion(string file, string player[], int player_mang[], int n){
    fstream fin(file);
    string data;
    while (!fin.eof())
    {
        int tim = 6;
        getline(fin, data);
        play(data, player, player_mang, n);
    }
}

void newGame(){
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
