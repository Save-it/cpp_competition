#include <bits/stdc++.h>
using namespace std;
int n, arr[10000], tmp[10000];

void merge(int start, int mid, int end) {
    int i = start;
    int j = mid + 1;
    int p = start;
    while (i <= mid && j <= end) {
        if (arr[i] < arr[j]) {
            tmp[p] = arr[i];
            i++; p++;
        } else {
            tmp[p] = arr[j];
            j++; p++;
        }
    }
    for ( ; i <= mid; i++) {
        tmp[p] = arr[i];
        p++;
    }
    for ( ; j <= end; j++) {
        tmp[p] = arr[j];
        p++;
    }
    for (int k = start; k <= end; k++) arr[k] = tmp[k];
}

void mergesort(int start, int end) {
    // cout << start << " : " << end << endl;
    if (start == end) return;

    int mid = start + (end - start) / 2;
    mergesort(start, mid);
    mergesort(mid + 1, end);

    merge(start, mid, end);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];

    mergesort(1, n);

    for (int i = 1; i <= n; i++) cout << tmp[i] << " ";

    return 0;
}
