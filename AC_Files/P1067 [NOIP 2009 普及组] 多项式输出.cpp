#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >>n;
	
	int x[n+1];
	for (int i = 0; i < n + 1; i++) cin >> x[i];
	
	stringstream ss;
	int a = 0;
	for (int i = 0; i < n - 1; i++) {
		if (x[i] != 0 && a == 0) {
			if (x[i] < -1) ss << x[i] << "x" << "^" << (n - i);
			if (x[i] > 1) ss << x[i] << "x" << "^" << (n - i);
			if (x[i] == -1) ss << "-x" << "^" << (n - i);
			if (x[i] == 1) ss << "x" << "^" << (n - i);
			a++;
			continue;
		}
		if (a > 0) {
			if (x[i] < -1) ss << x[i] << "x" << "^" << (n - i);
			if (x[i] > 1) ss << "+" << x[i] << "x" << "^" << (n - i);
			if (x[i] == -1) ss << "-x" << "^" << (n - i);
			if (x[i] == 1) ss << "+x" << "^" << (n - i);
		}
		
	}
	if (x[n - 1] < -1) ss << x[n - 1] << "x";
	if (x[n - 1] == -1) ss << "-x";
	if (x[n - 1] > 1) {
		if (n > 1) ss << "+" << x[n - 1] << "x";
		if (n == 1) ss << x[n - 1] << "x";
	}
	if (x[n - 1] == 1) {
		if (n > 1) ss << "+x";
		if (n == 1) ss << "x";
	}
	if (x[n] < 0) ss << x[n];
	if (n > 0 && x[n] > 0) ss << "+" << x[n];
	if (n == 0) ss << x[n];
	cout << ss.str();
    
    return 0;
}

