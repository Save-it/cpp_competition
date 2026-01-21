#include <bits/stdc++.h>
using namespace std;

string in;
long long n, num, tmp;

int main() {
    cin >> in >> n;

    num = in.size();
    while (n > num) {
        tmp = num;
        while(n > tmp) tmp *= 2;
        tmp /= 2;
        n -= tmp + 1;
        if (n == 0) n = tmp;
    }

    cout << in[n - 1];
    return 0;
}