#include<bits/stdc++.h> 
using namespace std;

struct score {
	int x;
	int a;
	int b;
	int c;
};

bool cmp(score a, score b) {
	int x = a.a + a.b + a.c;
	int y =b.a + b.b + b.c;
	if (x == y) return !(a.a > b.a);
	if (x == y && a.a == b.b) return a.x > b.x;
	return !(x > y);
}

int main() {
	int n;
	cin >> n;
	
	score s[n];
	for (int i = 0; i < n; i++) {
		s[i].x = i + 1;
		cin >> s[i].a;
		cin >> s[i].b;
		cin >> s[i].c;
	}

	sort(s, s + n, cmp);
	for (int i = n - 1; i > n - 6; i--) {
		cout << s[i].x << " ";
		cout << s[i].a + s[i].b + s[i].c << endl;
	}
	
	return 0;
}
