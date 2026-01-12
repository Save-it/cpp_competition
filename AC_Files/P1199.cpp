#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000;
int n, w[MAXN][MAXN], ans;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            cin >> w[i][j];
            w[j][i] = w[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        sort(w[i], w[i] + n + 1);
        ans = max(ans, w[i][n - 1]);
    }

    cout << 1 << endl << ans;

    return 0;
}