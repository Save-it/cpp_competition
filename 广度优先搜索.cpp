#include<bits/stdc++.h> 
using namespace std;

const int ju[9][9] = {{1, 1, 1, 1, 1, 1, 1, 1, 1},
						{1, 0, 1, 1, 1, 0, 1, 0, 0},
						{1, 1, 0, 0, 0, 0, 1, 0, 0},
						{1, 1, 0, 0, 1, 1, 0, 0, 0},
						{1, 1, 0, 1, 0, 0, 0, 1, 0},
						{1, 0, 0, 1, 0, 0, 0, 1, 1},
						{1, 1, 1, 0, 0, 0, 0, 0, 1},
						{1, 0, 0, 0, 1, 1, 0, 0, 1},
						{1, 0, 0, 0, 0, 1, 1, 1, 0}};

int s[9];
int a[101], b[101];

int out (int d) {
	int n = d;
	cout << char(a[d] + 64);
	while (b[d]) {
		d = b[d];
		cout << "--" << char(a[d] + 64);
	}
	cout << endl;
	for (int i = 0; i < n; i++) cout << a[i] << " ";
	cout << endl;
	for (int i = 0; i < n; i++) cout << b[i] << " ";
	cout << endl;
}

void bfs () {
	int i, head, tail;
	a[1] = 1;
	b[1] = 0;
	s[1] = 1;
	head = 0;
	tail = 1;
	
	do {
		head++;
		for (i = 1; i <= 8; i++)
			if (ju[a[head]][i] == 1 && s[i] == 0) {
				tail++;
				a[tail] = i;
				b[tail] = head;
				s[i] = 1;
				if (i == 8) {
					out(tail);
					head = tail;
					break;
				}
			}
	} while (head < tail);
}

int main() {
	bfs();
	
	return 0;
}
