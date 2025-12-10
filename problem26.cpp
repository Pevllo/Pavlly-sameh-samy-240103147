// https://codeforces.com/problemset/problem/1030/A
#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    bool hard=false;
    for(int i=0;i<n;i++){
        int opinion;
        cin >> opinion;
        if(opinion == 1){
            hard = true;
        }
    }
    if (hard) cout << "HARD";
    else cout << "EASY";
    return 0;
}