// https://codeforces.com/problemset/problem/236/A
#include <iostream>
using namespace std;
int main() {
    string w;
    int s=0;
    cin>>w;
    for(int i=0;i<w.length();i++){
       for(int j=i+1;j<w.length();j++){
            if(w[i]==w[j]){
              s--;
              break; }
       }
    s++;
        
    }
    if(s%2==0)
       cout<<"CHAT WITH HER!";
    else
        cout<<"IGNORE HIM!";
    return 0;
}