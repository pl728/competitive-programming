#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, l, r;
    cin >> n >> l >> r;

    int a[n];
    for(int i = 0; i < n; i++) {
        a[i] = (i + 1) * (r / (i + 1));
        if(a[i] < l) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
    return;
} 

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
         solve();
    }
}