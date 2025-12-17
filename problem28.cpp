// problem:https://codeforces.com/problemset/problem/339/A
#include<iostream>
using namespace std;

int main(){
    string s;
    cin >> s;

    int c1=0,c2=0,c3=0;

    for(char c : s){
        if(c=='1')
            c1++;
        else if (c=='2')
            c2++;
        else if (c=='3')
            c3++;
    }
    // zy el flag 
    bool first = true;


    while (c1--){
        if (!first)
            cout << "+";
        cout <<"1";
        first=false;
    } 
    
    while (c2--) {
        if (!first) cout << "+";
        cout << "2";
        first = false;
    }

    while (c3--) {
        if (!first) cout << "+";
        cout << "3";
        first = false;
    }


    return 0;

  
}