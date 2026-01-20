#include <bits/stdc++.h>
using namespace std;

const int MAXM = 1000000;
long long n, m, now, ans;

struct P{
    int x;
    int e;
} in[MAXM];

bool cmp(P a, P b) {
    return a.x < b.x;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> in[i].x >> in[i].e;
    } 

    sort(in, in + m, cmp);
    now = 0;
    ans = 0;
    for (int i = 0; i < m && now < n; i++) {
        if (now + in[i].e < n) {
            now += in[i].e;
            ans += in[i].e * in[i].x;
        } else {
            ans += (n - now) * in[i].x;
            now = n;
        }
    }
    cout << ans;

    return 0;
}