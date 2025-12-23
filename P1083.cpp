#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2000000;
const int MAXM = 2000000;
long long n, m, in[MAXN], re[MAXN], d, s, t;

int main() {
    cin >> m >> m;
    cin >> in[1];
    re[1] = in[1];
    for (int i = 2; i < n; i++) cin >> in[i];
    
    for (int i = 1; i <= m; i++) {
        cin >> d >> s >> t;
        for (int j = s; j <= t; j++) {
                in[j] -= d;
                if (in[j] < 0) {
                    cout << -1 << endl << i;
                    return 0;
                }
        }
    }
    cout << 0;

    return 0;
}