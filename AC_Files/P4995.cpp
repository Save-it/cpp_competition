#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10000;
long long n, in[MAXN], vd[MAXN], ans, now; 

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> in[i]; 

    sort(in, in + n);
    int i = 0;
    int j = n - 1;
    while (i <= j) {
        ans += pow(now - in[j], 2);
        now = in[j];
        j--;
        ans += pow(now - in[i], 2);
        now = in[i];
        i++;
    }

    cout << ans;

    return 0;
}