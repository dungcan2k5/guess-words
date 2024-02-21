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
void in_tu(string tu[]){
    cout<<"The word you need to guess has "<<tu->length()<<" letters: ";
    for (int i=0;i < tu->length();i++){
        cout<<"_";
    }
    cout<<endl;
}
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
    cout << "Enter the number of player: ";
    int n; cin >> n;
    cout << "\n";
    string player[n];
    int player_mang[n];
    for(int i = 0; i < n ; i++){
        string name; cin >> name;
        player[i] = name;
        player_mang[i] = 6;
    }
    // Nhập số lượng người chơi , tên người chơi
    
    
    inputQuestion("BoCauHoi.txt");
}
