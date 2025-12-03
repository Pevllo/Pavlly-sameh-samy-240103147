// https://codeforces.com/problemset/problem/677/A
#include<iostream>
using namespace std;

int main(){
    int h,n,a;
    int w =0;
    cin>>n>>h;
    for(int i=0;i<n;i++){
        cin>>a;
        if(a>h){
            w+=2;
        }else{
            w++;
        }
    }
    cout<<w<<endl;
    
return 0;
}