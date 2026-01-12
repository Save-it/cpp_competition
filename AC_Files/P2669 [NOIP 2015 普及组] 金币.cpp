#include<bits/stdc++.h> 
using namespace std;

int main() {
	
	int n;
	cin >> n;
	
	int g = 0;
	int dg = 1;
	
	for (int d = 0; d < n; dg++) {
		for (int i = 0; i < dg; i++) {
			g = g + dg;
			d++;
			if (d >= n) {
				cout << g;
				return 0;
			}
		}
	}
	
	cout << g;
	
	return 0;
}
