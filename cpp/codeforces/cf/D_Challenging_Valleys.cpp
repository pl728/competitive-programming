#include <bits/stdc++.h>
#define f(i,b) for (int i = 0; i < b; i++)
using ll = long long;
using namespace std;

const int M = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    f(i,n) {
        cin >> a[i];
    }
    vector<int> b(1);
    b[0] = a[0];
    for(int i = 1; i < n; i++) {
        if(a[i] != a[i-1]) {
            b.push_back(a[i]);
        }
    }
    int m = b.size();
    if(m == 1 || m == 2) {
        cout << "YES" << endl;
        return;
    }
    int numValleys = 0;
    if(b[0] < b[1]) {
        numValleys++;
    }
    if(b[m-1] < b[m-2]) {
        numValleys++;
    }
    for(int i = 1; i < m - 1; i++) {
        if(b[i] < b[i-1] && b[i] < b[i+1]) {
            numValleys++;
        }
    }
    if(numValleys > 1) cout << "NO" << endl;
    else cout << "YES" << endl;
    
}

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
         solve();
    }
}