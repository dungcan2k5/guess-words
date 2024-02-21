#include <iostream>
#include <fstream>
using namespace std;

// void in_tu(char tu[]){
//     for(int i = 0; i < tu.size(); i++){
//         cout << tu[i] << " ";
//     }
// }

void play(string data, int &tim){
    int so_luong = data.size();
    char tu[so_luong];
    cout <<"Number of words : " << so_luong << "\n"; // In ra số lượng chữ của từ
    for(int i = 0; i < so_luong; i++) tu[i] = data[i];

    
    int cnt[27] = {0};
    for(int i = 0; i < so_luong; i++) cnt[data[i] - 65]++; // Đếm số lượng các chữ cái xuất hiện của từ
    while(so_luong){
        char chu; cin >> chu;
        if(cnt[chu - 65] != 0){
            cout << "Have "<<cnt[chu - 65] << " letter " << chu << "\n"; // in ra số lần xuất hiện của từ của ki tự nhập vào 
            cout << "You have " << so_luong << " \n"; // in ra số mạng còn lại
            so_luong -= cnt[chu - 65];
        }else{
            tim--;
            cout << "You have " << so_luong << " \n"; // in ra số mạng còn lại
        }
    }
}

void inputQuestion(string file){
    fstream fin(file);
    string data; 
    while(!fin.eof()){
        int tim = 6;
        getline(fin, data);
        play(data, tim);
    }
}

void game(){
    //inputQuestion("BoCauHoi.txt");
    inputQuestion("BoCauHoi.txt");
}