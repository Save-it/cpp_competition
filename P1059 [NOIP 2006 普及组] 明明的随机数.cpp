#include<bits/stdc++.h>
using namespace std;

int findele(int* a, int b, int len) {
	for (int i = 0; i < len; i++) {
		if (a[i] == b) return 1;
	}
	return 0;
} 

int main() {
	int n;
	cin >> n;
	
	int a[n];
	fill(a, a + n, 0);
	int b;
	int c = n;
	for (int i = 0; i < n; i++) {
		cin >> b;
		if (!findele(a, b, n)) {
			a[i] = b;
			c--;
		}
	}
	
	int tmp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (a[j + 1] < a[j]) {
				tmp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = tmp;
			}
		}
	}
	
	cout << n - c << endl;
	for (int i = 0; i < n; i++) {
		if (a[i] != 0) cout << a[i] << " ";
	}
	
	return 0;
} 
