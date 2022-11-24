#include <bits/stdc++.h>
#define for(i,b) for (int i = 0; i < b; i++)
using ll = long long;
using namespace std;

const int M = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<int> x(n);
    for(i,n){
        cin >> x[i];
    }
    vector<int> y = x;
    sort(y.begin(), y.end());
    for(i,n) {
        if(x[i] == y[n-1]) {
            // if max element
            cout << x[i] - y[n-2] << " ";
        } else {
            cout << x[i] - y[n-1] << " ";
        }
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