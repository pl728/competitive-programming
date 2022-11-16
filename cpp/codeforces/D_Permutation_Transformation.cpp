#include <bits/stdc++.h>
using namespace std;

void build(int a[], int d[], int l, int r, int currentDepth) {
    if(r < l) {
        return;
    }
    if(l == r) {
        d[l] = currentDepth;
        return;
    }
    int m = l;
    for(int i = l + 1; i <= r; i++) {
        if(a[m] < a[i]) {
            m = i;
        }
    }
    d[m] = currentDepth;
    build(a, d, l, m - 1, currentDepth + 1);
    build(a, d, m + 1, r, currentDepth + 1);
}

void solve() {
    int n;
    cin >> n;
    int a[n];
    int d[n];
    for(int &x : a) {
        cin >> x;
    }
    build(a, d, 0, n-1, 0);
    for(int x : d) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
         solve();
    }
}