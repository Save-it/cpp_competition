#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	int i = 2;
	int b;
	while (i < n) {
		if (n % i == 0) {
			int a = 0;
//			cout << i << endl;
			for (int j = 2; j * j <= i; j++) {
				if (i % j == 0) {
					a++;
				}
			}
			if (a == 0) {
				b = i;
				i = n;
			}
		}
		i++;
	}
	
	if (b > (n / b)) {
		cout << b;
	} else {
		cout << n / b;
	}
	
	return 0;
}
