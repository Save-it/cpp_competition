#include<bits/stdc++.h> 
using namespace std;
int n, tmp;
vector<int> ans;



int dg(int a) {
	if (a == 1 || a == 2) return 1;
	return dg(a - 1) + dg(a - 2);
}

int main() {
	cin >> n;

	cout << dg(n);
	
	return 0;
}
