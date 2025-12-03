// https://codeforces.com/problemset/problem/112/A
#include<iostream>
using namespace std;
int main(){
    string s1,s2;
    cin>>s1>>s2;
    for(int i=0;i<s1.size();i++){
        int a=tolower(s1[i]);
        int b=tolower(s2[i]);
        if(a!=b){
            if (a<b){
                cout<<-1<<endl;
                return 0;
            }
            else{
                cout<<1<<endl;
                return 0;
            }
        }
    }
    cout<<0<<endl;
    return 0;
}