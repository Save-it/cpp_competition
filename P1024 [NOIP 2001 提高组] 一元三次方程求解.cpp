#include<bits/stdc++.h> 
using namespace std;

double a, b, c, d, x1, x2, x3;
double f(double x) {
	return a * x * x * x + b * x * x + c * x + d;
}

int main() {
	cin >> a >> b >> c >> d;
	
	for (int x = -100; x <= 100; x++) {
		x1 = x;
		x2 = x1 + 1;
		if (!f(x1)) {
        	printf("%.2f ", x1);
    	}
		else if (f(x1) * f(x2) < 0) {
			while (!(x2 - x1 < 0.0001)) {
				x3 = (x1 + x2) / 2;
				if (f(x1) * f(x3) < 0) x2 = x3;
				else x1 = x3;
			}
			printf("%.2f ", x1);
		}
	}
	
	return 0;
}
