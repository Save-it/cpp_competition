#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2000000;
const int MAXM = 2000000;
long long n, m, in[MAXN], re[MAXN], d, s, t;

int main() {
    cin >> m >> m;
    cin >> in[0];
    re[0] = in[0];
    for (int i = 1; i < n; i++) cin >> in[i];
    
    for (int i = 0; i < m; i++) {
        cin >> d >> s >> t;
        for (int j = s - 1; j < t; j++) {
                in[j] -= d;
                if (in[j] < 0) {
                    cout << -1 << endl << i + 1;
                    return 0;
                }
        }
    }
    cout << 0;

    return 0;
}