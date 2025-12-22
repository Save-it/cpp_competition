#include<bits/stdc++.h> 
using namespace std;

int n;
long long ans;
int main() {
	cin >> n;
	
	int l[n];
	for (int i = 0; i < n; i++) cin >> l[i];
	
	for (int i = 1; i < n; i++) if (l[i] > l[i - 1]) ans += l[i] - l[i - 1];
	
	cout << ans + l[0];
	
	return 0;
}
