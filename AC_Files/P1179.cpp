#include <bits/stdc++.h>
using namespace std;

int l, r, ans;

int main() {
    cin >> l >> r;

    for (int i = l; i <= r; i++) {
        string tmp = to_string(i);
        for (char a : tmp) if (a == '2') ans++;
    } 

    cout << ans;

    return 0;
}