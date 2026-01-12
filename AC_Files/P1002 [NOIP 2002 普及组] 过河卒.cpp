#include<bits/stdc++.h> 
using namespace std;

string pl(string a, string b) {
	int len = max(a.size(), b.size());
	while(a.size() < len) a = '0' + a;
	while(b.size() < len) b = '0' + b;
	
	int j = 0;
	string out = "";
	int tmp = 0;
	for (int i = len - 1; i > -1; i--) {
		int tmpa = a[i] - '0';
		int tmpb = b[i] - '0';
		tmp = tmpa + tmpb + j;
		if (tmp >= 10) {
			tmp -= 10;
			j = 1;
			if (tmp == 0) out = '0' + out;
			if (tmp > 0) out = char(tmp + '0') + out; 
		} else {
			j = 0;
			out = char(tmp + '0') + out;
		}
	}
	if (j == 1) out = '1' + out;
	
	return out;
}

struct point {
	int x = 0;
	int y = 0;
};
int xb, yb, xh, yh;
point hc[9];
string ps[100][100];
//vector<point> tmpl;

string dfs(int x, int y, point b) {
	if (x == b.x && y == b.y) {
		return "1";
	}
	for (point p : hc) {
		if (x == p.x && y == p.y) return "0";
	}
	string m = "";
	string n = "";
	if (ps[x][y] == "") {
		if(y != b.y) m = dfs(x, y + 1, b);
		if(x != b.x) n = dfs(x + 1, y, b);
		ps[x][y] = pl(m , n);
		return ps[x][y];
	} else {return ps[x][y];}
}

int main() {
	cin >> xb >> yb >> xh >> yh;
	point b, h;
	b.x = xb; b.y = yb;
	h.x = xh; h.y = yh;
	hc[0] = h;
	hc[1].x = h.x + 2; hc[1].y = h.y + 1;
	hc[2].x = h.x + 1; hc[2].y = h.y + 2;
	hc[3].x = h.x - 1; hc[3].y = h.y + 2;
	hc[4].x = h.x - 2; hc[4].y = h.y + 1;
	hc[5].x = h.x - 2; hc[5].y = h.y - 1;
	hc[6].x = h.x - 1; hc[6].y = h.y - 2;
	hc[7].x = h.x + 1; hc[7].y = h.y - 2;
	hc[8].x = h.x + 2; hc[8].y = h.y - 1;
//	for (point p : hc) cout << p.x << "," << p.y << "  ";
//	cout << endl;
	
	cout << dfs(0, 0, b);
	
	return 0;
}
