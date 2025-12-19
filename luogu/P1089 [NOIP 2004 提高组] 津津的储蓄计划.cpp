#include<bits/stdc++.h>
using namespace std;

int main() {
	int m = 0;
	int c = 0;
	
	int y[12];
	for (int i = 0; i < 12; i++) {
		cin >> y[i];
	}
	
	int i;
	for (i = 0; i < 12; i++) {
		m += 300;
		if (y[i] <= m) {
			m -=  y[i];
			c += floor(m / 100) * 100;
			m -= floor(m / 100) * 100;
		} else {
			cout << -(i + 1);
			i += 12;
		}
//		cout << i << " " << m << " " << c << endl;
	}
	
	if (i == 12) {
		cout << m + (c * 1.2);
	}
	
	return 0;
}
