#include <bits/stdc++.h>

using namespace std;

void solve() {
    int x, y;
    cin >> x >> y;
    // 2 2 -> x-1 y
    // 2 7 -> 1 7 -> x-1 y
    if(x >= y) {
        cout << x-1 << " " << y << "\n";
    } else {
        cout << x-1 << " " << y << "\n";
    }

    return;
}

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
         solve();
    }
}
