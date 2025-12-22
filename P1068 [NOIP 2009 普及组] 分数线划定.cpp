#include<bits/stdc++.h> 
using namespace std;

struct s {
	int id;
	int score;
};

bool cmp(s a, s b) {
	if (a.score == b.score) return a.id < b.id;
	return a.score > b.score;
}

int main() {
	int n, m;
	cin >> n >> m;
	
	int f = floor(m * 1.5);
	
	s l[n];
	for (int i = 0; i < n; i++) {
		cin >> l[i].id >> l[i].score;
	}
	
	int g = 0;
	sort(l, l + n, cmp);
	for (int i = 0; i < n; i++) {
		if (l[i].score >= l[f - 1].score) g++;
	}
	
	cout << l[f - 1].score << " " << g << endl;
	for (int i = 0; i < g; i++) {
		cout << l[i].id << " " << l[i].score << endl;
	}
	
	return 0;
}
