#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000000;
long long ans;
// int n, S[MAXN], A[MAXN], vd[MAXN], now, tmp1, tmp2, tmp3, tmp4, m;
int n, s[MAXN], m[MAXN], mf[MAXN]; // 疲劳前缀和 前i个最大值 后i个最大值 

struct z{
    int s;
    int a;
} in[MAXN];

bool cmp(z a, z b) {
    return a.a > b.a;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> in[i].s;
    for (int i = 1; i <= n; i++) cin >> in[i].a;

    sort(in + 1, in + n + 1, cmp); //按疲劳排序 
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + in[i].a;
    for (int i = 1; i <= n; i++) m[i] = max(m[i - 1], in[i].s * 2); //前i个最大值 
    for (int i = n; i >= 1; i--) mf[i] = max(mf[i + 1], in[i].s * 2 + in[i].a); //后i个最大值
    for (int x = 1; x <= n; x++) cout << max(s[x] + m[x], s[x - 1]+ mf[x]) << endl;

    // for (int i = 1; i <= n; i++) {
    //     now = 0;
    //     m = 0;
    //     for (int x = 1; x <= i; x++) {
    //         tmp1 = 0;
    //         tmp2 = 0;
    //         tmp3 = 0;
    //         for (int j = 1; j <= n; j++) {
    //             if (vd[j] == 1) continue;
    //             tmp1 = A[j];
    //             if (S[j] > m) {
    //                 tmp1 += abs(S[j] - m) * 2;
    //             }
    //             if (tmp1 > tmp2) {
    //                 tmp2 = tmp1;
    //                 tmp3 = j;
    //             }
    //         }
    //         m = max(S[tmp3], m);
    //         vd[tmp3]++;
    //         now = S[tmp3];
    //         ans += tmp2;
    //     }
    //     cout << ans << endl;
    //     fill(vd + 1, vd + 1 + n, 0);
    //     ans = 0;
    // }

    return 0;
}