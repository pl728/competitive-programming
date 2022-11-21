#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    int a[n];
    int c[n + 1] = {0};
    for(int &x : a) {
        cin >> x;
        c[x]++;
    }

    int ans = 0;
    for(int s = 2; s <= 2 * n; s++) {
        int curr = 0;
        for(int i = 1; i < (s + 1) / 2; i++) {
            if(s - i > n) continue;
            else curr += min(c[i], c[s-i]);
        }
        if(s % 2 == 0) curr += c[s / 2] /` 2;
        ans = max(curr, ans);
    }
    cout << ans << endl;
    return;

}

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
         solve();
    }
}