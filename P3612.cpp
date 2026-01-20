#include <bits/stdc++.h>
using namespace std;

string in;
long long n, p, tmp;
string ps[1000000];

int main() {
    cin >> in >> n;

    ps[p] = in;
    n -= ps[p].size();
    p++;
    // tmp += ps[p].size();
    while(n > 0) {
        ps[p] += ps[p - 1][ps[p - 1].size() - 1];
        for (int i = 0; i < p; i++) ps[p] += ps[i];
        ps[p].pop_back();
        n -= ps[p].size();
        p++;
    }

    cout << ps[p - 1][ps[p - 1].size() + n - 1];
    return 0;
}
