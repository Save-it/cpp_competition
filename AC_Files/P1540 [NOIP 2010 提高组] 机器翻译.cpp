#include<bits/stdc++.h> 
using namespace std;

int m, n, head, tail, ans, q[2000];

int finele(int f) {
	for (int i = head; i <= tail; i++) 
		if (q[i] == f) return i;
	return -1;
}

int main() {
	cin >> m >> n;
	int p[n];
	for (int i = 0; i < n; i++) cin >> p[i];
	
	head++;
	for (int now : p) {
		if (finele(now) == -1) {
			ans++;
			tail++;
			q[tail] = now;
			if (tail - head == m) {
				head++;
			}
		}
//		for (int j = head; j <= tail; j++) cout << q[j] << " ";
//		cout << endl;
	}
	
	cout << ans;
	
	return 0;
}
