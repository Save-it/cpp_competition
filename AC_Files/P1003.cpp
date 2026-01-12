#include <bits/stdc++.h>
using namespace std;

const int MAXN = 20000;
int n, x, y, m[MAXN][2][2], a, b, g, k, ans;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> g >> k;
        m[i][0][0] = a;
        m[i][0][1] = b; 
        m[i][1][0] = a + g; 
        m[i][1][1] = b + k; 
    }

    cin >> x >> y;

    for (int i = 0; i < n; i++) {
        if (m[i][0][0] <= x && x <= m[i][1][0] && m[i][0][1] <= y && y <= m[i][1][1]) ans = i + 1;
    }

    if (ans != 0) cout << ans;
    else cout << -1;

    return 0;
}