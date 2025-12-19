#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int z = 1;
	
	stringstream ss;
	if (n >= 0) {
		ss << n;
	} else {
		ss << -n;
		z = -1;
	}
	
	string str = ss.str();
	
	for (int i = 0; i < ceil(str.size() / 2); i++) {
		char a;
		a = str[i];
		str[i] = str[str.size() - 1 - i];
		str[str.size() - 1 - i] = a;
	}
	
	if (z == 1) {
		cout << atoi(str.c_str()); 
	} else {
		cout << -atoi(str.c_str());
	}
	
	
	return 0;
}
