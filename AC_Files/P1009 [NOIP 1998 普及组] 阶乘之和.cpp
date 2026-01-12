#include<bits/stdc++.h> 
using namespace std;

int main() {
	
	int n;
	cin >> n;
	
	long long s = 0;
	for (int i = 1; i <= n; i++) {
		long long r = 1;
		for (int j = 1; j <= i; j++) {
			r = r * j;
		}
		s = s + r;
	} 
	
	cout << s;
	
	return 0;
}
