#include<bits/stdc++.h>
using namespace std;

int main() {
    int p1, p2, p3;
    cin >> p1 >> p2 >> p3;
    
    string str;
    cin >> str;
    
    int i = 0;
    string tmp = "";
    string out = "";
    if (p3 == 1) {
	    for (char ch:str) {
	    	if (ch == '-' && str[i + 1] - str[i - 1] > 0 && i != 0 && ((str[i - 1] >= 65 && str[i + 1] <= 122) || (str[i - 1] >= 48 && str[i + 1] <= 57))) {
	    		if (p1 == 1) {
	    			for (int j = str[i - 1] + 1; j < str[i + 1]; j++) {
	    				for (int k = 0; k < p2; k++) {
	    					tmp += j;
						}
					}
				} else if (p1 == 2) {
					for (int j = str[i - 1] + 1; j < str[i + 1]; j++) {
	    				int k = 0;
	    				while (k < p2) {
	    					if (j - 32 >= 65 && j <= 122 && j >= 97) {
	    						tmp += j - 32;
							} else if (j <= 57 && j >= 48) {
								tmp += j;
							} else {
								tmp += '-';
								break;
							}
							k++;
						}
					}
				} else if (p1 == 3) {
					for (int j = str[i - 1] + 1; j < str[i + 1]; j++) {
	    				for (int k = 0; k < p2; k++) {
	    					tmp += '*';
						}
					}
				}
			} else {
				tmp += ch;
			}
			out += tmp;
			tmp = "";
			i++;
		}
	} else if (p3 == 2) {
		for (char ch:str) {
	    	if (ch == '-' && str[i + 1] - str[i - 1] > 0 && i != 0 && ((str[i - 1] >= 65 && str[i + 1] <= 122) || (str[i - 1] >= 48 && str[i + 1] <= 57))) {
	    		if (p1 == 1) {
	    			for (int j = str[i + 1] - 1; j > str[i - 1]; j--) {
	    				for (int k = 0; k < p2; k++) {
	    					tmp += j;
						}
					}
				} else if (p1 == 2) {
	    			for (int j = str[i + 1] - 1; j > str[i - 1]; j--) {
	    				int k = 0;
	    				while (k < p2) {
	    					if (j - 32 >= 65 && j <= 122 && j >= 97) {
	    						tmp += j - 32;
							} else if (j <= 57 && j >= 48) {
								tmp += j;
							} else {
								tmp += '-';
								break;
							}
							k++;
						}
					}
				} else if (p1 == 3) {
	    			for (int j = str[i + 1] - 1; j > str[i - 1]; j--) {
	    				for (int k = 0; k < p2; k++) {
	    					tmp += '*';
						}
					}
				}
			} else {
				tmp += ch;
			}
			out += tmp;
			tmp = "";
			i++;
		}
	}
    
    
    cout << out;
    
    return 0;
}
