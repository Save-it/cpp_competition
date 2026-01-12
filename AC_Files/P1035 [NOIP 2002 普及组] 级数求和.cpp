#include<bits/stdc++.h> 
using namespace std;

int main() {
	
	int k;
	cin >> k;
	
	int n = 1;
	double a = 0;
	while (a <= k) {
		a = a + (1.0 / n);
		n++;
	}
	
	cout << n - 1;
	
	return 0;
}
