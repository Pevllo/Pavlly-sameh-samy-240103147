// https://codeforces.com/problemset/problem/116/A
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int inside = 0;   
    int answer = 0;   

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        inside -= a;  
        inside += b;  

        if (inside > answer)
            answer = inside;  
    }

    cout << answer;
}