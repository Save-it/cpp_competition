#include<bits/stdc++.h> 
using namespace std;

int n, w;
long long ans;
int main() {
	cin >> w >> n;
	int l[n];
	for (int i = 0; i < n; i++) cin >> l[i];
	sort(l, l + n);
	
	int f = 1;
	while (f != 0) {
		f = 0;
		for (int i = 0; i < n; i++) {
			if (l[i] != 0) {
				int tmp1 = w - l[i];
				int tmp2 = 0;
				int p = 0;
//				cout << l[i] << " ";
				l[i] = 0;
				for (int j = 0; j < n; j++) {
					if (l[j] <= tmp1 && l[j] > tmp2) {
						tmp2 = l[j];
						p = j;
					}
				}
//				cout << l[p] << endl;
				l[p] = 0;
				ans++;
//				for (int j : l) cout << j << " ";
//				cout << endl;
			}
			f += l[i];
		}
	}
	
	cout << ans;
	
	return 0;
}
