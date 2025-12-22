#include<bits/stdc++.h> 
using namespace std;
const int MAXN = 1000;
int n, in[1000], m, s;

void swap(int p1, int p2) {
	int tmp = in[p1];
	in[p1] = in[p2];
	in[p2] = tmp;
}

void print() {
	for (int i = 0; i < m; i++) {
		if (in[i] == 0) cout << "o";
		else if (in[i] == 1) cout << "*";
		else if (in[i] == -1) cout << "-";
	}
	cout << endl;
}

void comb() {
	print();
	if (in[0] == in[1] == -1) return;
	for (int i = 0; i < s; i++) {
		if (s == 7) {
			swap(3, 8);
			swap(4, 9);
			print();
			swap(3, 6);
			swap(4, 7);
			print();
			swap(1, 6);
			swap(2, 7);
			print();
			swap(0, 6);
			swap(1, 7);
			print();
			return;
		} else if (in[i] == 0 && in[i + 1] == 1) {
//			cout << "o*" << endl;
			swap(i, s - 1);
			swap(i + 1, s);
			s -= 2;
			comb();
			i += 1000;
		} else if (in[i] == -1 && in[i + 1] == -1) {
//			cout << "--" << endl;
			swap(i, s - 1);
			swap(i + 1, s);
			comb();
			i += 1000;
		}
	}
}

int main() {
	cin >> n;
	m = n * 2 + 2;
	s = m - 1;
	for (int i = 0; i < n; i++) {
		in[i] = 0;
		in[i + n] = 1;
	}
	in[m - 1] = in[m - 2] = -1;
	
	comb();
	
	return 0;
}
