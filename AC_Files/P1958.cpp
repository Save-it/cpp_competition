#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000;
int a, b, n, fix[MAXN][2], vd[MAXN][MAXN], ans;

bool search(int x, int y) {
    for (int i = 0; i < n; i++) {
        if (fix[i][0] == x && fix[i][1] == y) return true;
    }
    return false;
}

int dfs(int x, int y) {
    // cout << x << " " << y << endl;
    if (search(x, y)) return 0;
    if (x == a && y == b) return 1;
    if (x > a || y > b) return 0;
    if (vd[x][y] == 0) {
        vd[x][y] += dfs(x + 1, y);
        vd[x][y] += dfs(x, y + 1);
    }
    // cout << vd[x][y] << endl;
    return vd[x][y];
}

int main() {
    cin >> a >> b >> n;
    for (int i = 0; i < n; i++) cin >> fix[i][0] >> fix[i][1];

    ans = dfs(1, 1);

    cout << ans;

    return 0;
}