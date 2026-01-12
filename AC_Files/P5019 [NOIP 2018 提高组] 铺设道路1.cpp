#include<bits/stdc++.h> 
using namespace std;

int n;
long long ans;
int main() {
	cin >> n;
	
	int l[n];
	for (int i = 0; i < n; i++) cin >> l[i];
	
	int f = 1;
	while (f != 0) {
		int p = f = 0;
		int p1 = -1;
		int p2 = -1;
		for (int i = 0; i < n; i++) {
			if (l[i] != 0 && p == 0) {
				p1 = i;
				p++;
			}
			if ((l[i + 1] == 0 || i == n - 1) && p == 1) {
				p2 = i + 1;
				p--;
			}
			if (p1 != -1 && p2 != -1) {
				int m = 10000;
				for (int j = p1; j < p2; j++) m = min(m, l[j]);
				for (int j = p1; j < p2; j++) l[j] -= m;
//				cout << p1 + 1 << " " << p2 << " " << m << endl;
//				for (int k : l) cout << k << " ";
//				cout << endl;
				ans += m;
				p1 = -1;
				p2 = -1;
			}
			f += l[i];
		}
	}
	
	cout << ans;
	
	return 0;
}
