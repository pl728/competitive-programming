#include <bits/stdc++.h>
#define for(i,b) for (int i = 0; i < b; i++)
using ll = long long;
using namespace std;

const int M = 1e9 + 7;

void solve() {
    int n; cin >> n;
    // calculate 2^n
    // 2^n = 2*2*2*...*2 
    int ans = 1;
    for(i,n) {
        ans = 2 * ans % M;
    }
    cout << ans;
}

int main() {
    solve();
}