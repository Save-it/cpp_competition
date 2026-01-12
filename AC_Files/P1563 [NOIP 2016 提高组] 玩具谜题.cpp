#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
	cin >> n >> m;
	
	int pos[n];
	string name[n];
	for (int i = 0; i < n; i++) {
		cin >> pos[i] >> name[i];
	}
	
	int now = 0;
	for (int i = 0; i < m; i++) {
		int to, g;
		cin >> to >> g;
		if (to + pos[now] == 1) {
			now += g;
		} else if (to + pos[now] == 2 || to + pos[now] == 0) {
			now -= g;
		}
		if (now >= n) {
			now = now % n;
		} else if (now < 0) {
			now = now % n + n;
		}
	}
	
	cout << name[now];
    
    return 0;
}
