// problem number 546A codeforces:https://codeforces.com/problemset/problem/546/A
#include<iostream>
using namespace std;
int main(){
      int k,w,n,ans=0;
      cin>>k>>w>>n;
        for(int i=1;i<=n;i++){
            ans+=i*k;
        } 
        if(ans>w){
            cout<<ans-w<<endl;
        }else{              
            cout<<0<<endl;
        }
    return 0;

}
