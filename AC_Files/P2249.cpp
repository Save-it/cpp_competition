#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000000;
int n, m, in[MAXN], tmp, ans;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> in[i];
        
    }
    for (int i = 0; i < m; i++) {
        cin >> tmp;
        ans = lower_bound(in, in + n, tmp) - in;
        if (tmp != in[ans]) cout << -1 << " ";
        else cout << ans + 1 << " ";
    }

    return 0;
}