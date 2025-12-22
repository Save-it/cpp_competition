#include<bits/stdc++.h> 
using namespace std;

int n;
long long ans;
int p[10000];
int main() {
	cin >> n;
	
	int l[n];
	for (int i = 0; i < n; i++) cin >>l[i];
	
	for (int i : l) {
		for (int j : l) {
			for (int k : l) {
				if (j != i && j != k && k != i && j + k == i && !p[i]) {
					ans++;
					p[i]++;
				}
			}
		}
	}
	
	cout << ans;
	
	return 0;
}
