#include<bits/stdc++.h>
using namespace std;

int c(string a, string b) {
	return (a + b) > (b + a); 
}

int main() {
	int n;
	cin >> n;
	
	string a[n];
	for (int i = 0; i < n; i++) cin >> a[i];

	sort(a, a + n, c);
	for (int i = 0; i < n; i++) cout << a[i];

	return 0;
}
