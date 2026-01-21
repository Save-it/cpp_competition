#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000;
int n, cj, bjc, lw, jxj[MAXN], ans2, ans3;
char gb, xb;
string xm, ans1;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> xm >> cj >> bjc >> gb >> xb >> lw;
        if (cj > 80 && lw >= 1) jxj[i] += 8000;
        if (cj > 85 && bjc > 80) jxj[i] += 4000;
        if (cj > 90) jxj[i] += 2000;
        if (cj > 85 && xb == 'Y') jxj[i] += 1000;
        if (bjc > 80 && gb == 'Y') jxj[i] += 850;
        ans3 += jxj[i];
        if (jxj[i] > ans2) {
            ans1 = xm;
            ans2 = jxj[i];
        }
    }

    cout << ans1 << endl << ans2 << endl << ans3;

    return 0;
}