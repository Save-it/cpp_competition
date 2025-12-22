#include<bits/stdc++.h> 
using namespace std;

int n;
long long ans;
int main() {
	cin >> n;
	
	int l[n];
	for (int i = 0; i < n; i++) cin >> l[i];
	
	for (int i = 1; i < n; i++) {
		int tmp = 0;
		int p = 0;
		int now = 0;
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < n; k++) {
				if (now == 0 && l[k] != 0) {
					now = l[k];
					p = k;
				}
				if (now > l[k] && l[k] != 0) {
					now = l[k];
					p = k;
				}
			}
			tmp += now;
			l[p] = 0;
			now = 0;
		}
		l[p] = tmp;
		ans += tmp;
//		for (int j : l) cout << j << " ";
//		cout << endl;
	}
	
	cout << ans;
	
	return 0;
}
