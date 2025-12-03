// https://codeforces.com/problemset/problem/734/A
#include<iostream>
using namespace std;

int main(){
    int n;
    string w;
    int A=0;
    int B=0;
    cin>>n;
    cin >> w;
    for (char c : w) {
    if (c == 'A') A++;
    else if (c == 'D') B++;
}

    if (A>B){
        cout << "Anton" ;
    }else if (B>A){
        cout << "Danik";
    }else{
        cout<<"Friendship" ;
    }
 return 0;   
}