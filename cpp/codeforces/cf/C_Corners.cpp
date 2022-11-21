#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; int m;
    cin >> n >> m;

    int a[n][m];
    string s;
    int ones = 0;
    for(int i = 0; i < n; i++) {
        cin >> s;
        for(int j = 0; j < m; j++) {
            a[i][j] = s[j] - '0';
            ones += a[i][j];
        }
    }

    int minn = 1e9;
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < m-1; j++) {
            int count = a[i][j] + a[i + 1][j] + a[i][j + 1] + a[i + 1][j + 1];
            if(count == 0) continue;
            minn = min(minn, count);
        }
    }
    if(ones == 0) cout << 0 << endl;
    else {
        if(minn == 1 || minn == 2) {
            cout << ones << endl;
        } else if(minn == 3) {
            cout << ones - 1 << endl;
        } else {
            cout << ones - 2 << endl;
        }
    }
}

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
         solve();
    }
}