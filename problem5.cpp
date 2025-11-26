// https://codeforces.com/problemset/problem/158/A
#include <iostream>
using namespace std;

int main()
{
    int n;
    int k;
    cin >> n >> k;
    int x[50];
    for(int i=0;i<=n;i++)
    {
        cin >> x[i];
    }
    int count=0;

    for (int i=0; i <= n;i++)
    {
        if (x[i]>=x[k-1]&&x[i]>0){
            count++;
        }
    }
    
    cout << count << endl;
    

    return 0;
}
