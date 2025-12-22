#include<bits/stdc++.h> 
using namespace std;

int main() {
	
	int n;
	cin >> n;
	
	stringstream ss;
	ss << n;
	string s = ss.str();
	cout << s << endl;
	int r = 0;
	for (int i = s.size(); i != 0; i--) {
//		cout << i << endl;
		r += (s[i - 1] - '0') * pow(10, i - 1);
//		cout << r << endl;
//		cout << int(s[i] - '0') << endl;
	}
	r += s[0] - '0';
	
	cout << r;
	
	return 0;
}
