#include<bits/stdc++.h> 
using namespace std;

int main() {
	
	int n, x;
	cin >> n >> x;
	
	stringstream ss1;
	ss1 << x;
	string y = ss1.str();
//	cout << y << endl;
	int r = 0;
	for (int i = 1; i <= n; i++) {
		stringstream ss2;
		ss2 << i;
		string s = ss2.str();
//		cout << s << endl;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == y[0]) {
				r++;
			}
		}
	}
	
	cout << r;
	
	return 0;
}
