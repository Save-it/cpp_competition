#include<bits/stdc++.h> 
using namespace std;
const int MAXN = 1000000;
long long n, ans, in[MAXN], re[MAXN], tmp[7][MAXN], p[7]; 

int main() {
	cin >> n;
	cin >> in[1];
//	cout << n << endl;
	re[1] = in[1];
	p[0]++;
    tmp[re[1] % 7][p[re[1] % 7]] = 1;
    p[re[1] % 7]++;
    
	for (long long i = 2; i <= n; i++) {
		cin >> in[i];
		re[i] = re[i - 1] + in[i];
//		cout << re[i] % 7 << " ";
        tmp[re[i] % 7][p[re[i] % 7]] = i;
        p[re[i] % 7]++;
//      cout << i << endl;
//		if (i % 500 == 0) cout << i << endl;
	}
//	cout << 1 << endl;
    for (int i = 0; i < 7; i++) {
//    	cout << tmp[i][p[i] - 1] << " " << tmp[i][0] << endl;
        ans = max(ans, tmp[i][p[i] - 1] - tmp[i][0]);
    }
    
	cout << ans;
	
	return 0;
}
