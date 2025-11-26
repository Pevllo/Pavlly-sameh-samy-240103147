// https://codeforces.com/problemset/problem/2172/A
#include <iostream>
using namespace std;
int main() {
    int a,b,c;
    cin>>a>>b>>c;
    int min,max;
    if(a>c&&a>b){
        max=a;
    }else if(b>a&&b>c){
        max=b;
    }else{
        max=c;
    }
    if(a<c&&a<b){
        min=a;
    }else if(b<a&&b<c){
        min=b;
    }else{
        min=c;
    }
    
    int score=max-min;
    int median=a+b+c-max-min;
    if(score>=10){
        cout<<"check again"<<endl;
    }else{
        cout<<"final "<<median;
    }
    

    return 0;
}