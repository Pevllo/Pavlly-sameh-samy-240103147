#include <iostream>
using namespace std;

int main()
{
   int n;
   cin>>n;
   int count=0; 
    for (int i=0;i<n;i++)
    {
        string bit;
        cin>>bit;
        if (bit=="++X" || bit=="X++")
        {
            count++;
        }else{
            count--;
        }
        
    }
    cout << count <<endl;

    return 0;
}


