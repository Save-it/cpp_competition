#include<bits/stdc++.h> 
using namespace std;

struct status {
	string a = "";
	string b = "";
	int x;
};

vector<int> z1;
vector<int> z2;
//vector<status> ss;
int ss[10000][10000];
int check() {
	int a = z1.size(); 
	int b = z2.size();
	if (ss[a][b] != 0) return ss[a][b];
	return 0;
}

void push(int x) {
	int a = z1.size();
	int b = z2.size();
	ss[a][b] = x;
}


int dfs(int x) {
	if (z1.size() + z2.size() == 0) return 1;
	if (check() == 0) {
		int a = 0; 
		int b = 0;
		if (z1.size() > 0) {
			int now = z1[z1.size() - 1];
			z2.push_back(now);
			z1.pop_back();
			a = dfs(x + 1);
			z1.push_back(now);
			z2.pop_back();
		}
		if (z2.size() > 0) {
			int now = z2[z2.size() - 1];
			z2.pop_back();
			b = dfs(x + 1);
			z2.push_back(now);
		}
		push(a + b);
		return a + b;
	} else {return check();}
}

int main() {
	int n;
	cin >> n;
	
	for (int i = n; i > 0; i--) z1.push_back(i);
	
	cout << dfs(1);
	
	return 0;
}
