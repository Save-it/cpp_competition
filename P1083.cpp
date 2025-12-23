#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1000000;
const int MAXM = 1000000;
int n, m, in[MAXN], d, s, t;

int main() {
    cin >> n >> m;
    int l[n + 1][n + 1];
    for (int i = 1; i <= n; i++) fill(l[i], l[i] + n + 1, 999999999);
    for (int i = 1; i <= n; i++) {
        cin >> in[i];
        for (int j = n; j >= i; j--) {
            l[i][j] = min(l[i][j - 1], in[i]);
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            cout << l[i][j] << " ";
        }
        cout << endl;
    }

    // for (int i = 1; i <= m; i++) {
    //     cin >> d >> s >> t;
    //     for (int j = s; j <= t; j++) {
    //         in[j] = in[j] - d;
    //         if (in[j] < 0) {
    //             cout << -1 << endl << i;
    //             return 0;
    //         }
    //     }
    // }
    cout << 0;

    return 0;
}