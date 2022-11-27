#include <bits/stdc++.h>
#define F(i,a,b) for (int i = a; i < b; i++)
using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n];
    long long ugliness = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(i == 0 || i == n - 1) {
            ugliness += a[i];
        }
        if(i > 0) {
            ugliness += abs(a[i] - a[i-1]);
        }
    }

    if(n == 1) {
        cout << a[0] << endl;
        return;
    }

    F(i,1,n-1) {
        if(a[i] > a[i-1] && a[i] > a[i+1]) {
            // max(a[i-1], a[i+1]) operations, a[i] - max(a[i-1], a[i+1])
            ugliness -= a[i] - max(a[i-1], a[i+1]);
            a[i] = max(a[i-1], a[i+1]);
        }
    }
    if(a[0] > a[1]) ugliness -= a[0] - a[1];
    if(a[n-1] > a[n-2]) ugliness -= a[n-1] - a[n-2];
    cout << ugliness << endl;
}

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
         solve();
    }
}