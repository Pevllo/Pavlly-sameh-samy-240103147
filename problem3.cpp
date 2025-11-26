// https://codeforces.com/problemset/problem/71/A
#include <iostream>
using namespace std;

int main() {
    int num_of_problems;
    cin >> num_of_problems;

    int p1,p2,p3;
    int count=0;

    for (int i=0; i<num_of_problems; i++) {
        cin >>p1>>p2>>p3;
        if (p1+p2+p3>=2) {
            count++;
        }
    }

    cout <<count<<endl;
    return 0;
}