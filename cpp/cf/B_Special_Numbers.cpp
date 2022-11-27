#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int M = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    // 0, 1, 2, 3, 4, 5
    // 0, 1, 0+1, 2, 0+2, 1+2, 0+1+2, 3, 
    // 
    ll p = 1;
    ll ans = 0;

    for(int i = 0; i < 31; i++) {
        if(k & (1 << i)) {
            ans = (ans + p) % M;
        }
        p *= n;
        p %= M;
    }

    cout << ans << "\n";
}

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
         solve();
    }
}