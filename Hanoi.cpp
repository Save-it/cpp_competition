#include<bits/stdc++.h> 
using namespace std;
int in1;
char in2, in3, in4;

void mov(int n, char a, char c, char b) {
	if(n == 0) return;
	mov(n - 1, a, b, c);
	cout << a << "->" << n << "->" << c << endl;
	mov(n - 1, b, c, a);
}

int main() {
	cin >> in1 >> in2 >> in3 >> in4;
	mov(in1, in2, in3, in4);
	
	return 0;
}
