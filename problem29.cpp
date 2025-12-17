// problem:https://codeforces.com/problemset/problem/59/A
#include <iostream>
#include <cctype>
using namespace std;

int main() {
    string s, result = "";
    cin >> s;

    int upper = 0, lower = 0;

    for (char c : s) {
        if (isupper(c)) upper++;
        else lower++;
    }

    for (char c : s) {
        if (upper > lower)
            result += toupper(c);
        else
            result += tolower(c);
    }

    cout << result;
    return 0;
}
