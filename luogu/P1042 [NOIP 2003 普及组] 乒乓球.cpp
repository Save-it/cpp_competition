#include<bits/stdc++.h>
using namespace std;

int main() {
	int s11 = 1;
	int s21 = 1;
	int w11[10000];
	int w21[10000];
	int l11[10000];
	int l21[10000];
	fill(w11, w11 + 10001, 0);
	fill(w21, w21 + 10001, 0);
	fill(l11, l11 + 10001, 0);
	fill(l21, l21 + 10001, 0);
	for (int i = 0; i < 3000; i++) {
		string r;
		cin >> r;
		for (int j = 0; j < r.size(); j++) {
			if (r[j] == 'W') {
				w11[s11]++;
				w21[s21]++;
			} 
			if (r[j] == 'L') {
				l11[s11]++;
				l21[s21]++;
			}
			if (max(w11[s11], l11[s11]) >= 11 && abs(w11[s11] - l11[s11]) >= 2) {
				s11++;
			}
			if (max(w21[s21], l21[s21]) >= 21 && abs(w21[s21] - l21[s21]) >= 2) {
				s21++;
			}
			if (r[j] == 'E') {
				i = 3000;
				break;
			}
		}
	}
	
//	cout << s11 << " " << s21 << endl;
	
	for (int i = 1; i <= s11; i++) {
		cout << w11[i] << ":" << l11[i] << endl;
	}
	cout << endl;
	for (int i = 1; i <= s21; i++) {
		cout << w21[i] << ":" << l21[i] << endl;
	}
	
	return 0;
}

