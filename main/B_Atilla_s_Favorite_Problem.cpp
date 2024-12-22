#include <bits/stdc++.h>
#define for(i,b) for (int i = 0; i < b; i++)
using ll = long long;
using namespace std;

const int M = 1e9 + 7;

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    int lastChar = -1;
    for(i,n) {
        lastChar = max(lastChar, (int) s[i]);
    }

    cout << lastChar - 96 << endl;
}

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
         solve();
    }
}