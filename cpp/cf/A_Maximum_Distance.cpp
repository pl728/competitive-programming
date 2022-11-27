#include <bits/stdc++.h>
#define F(i,a,b) for (int i = a; i < b; i++)
using namespace std;

void solve() {
    int N; cin >> N;
    vector<int> x(N);
    vector<int> y(N);
    F(i,0,N) cin >> x[i];
    F(i,0,N) cin >> y[i];

    int ans = 0;
    F(i,0,N) {
        F(j,i+1,N) {
            // sqrt()
            int a = pow((y[j] - y[i]), 2) + pow((x[j] - x[i]), 2);
            ans = max(ans, a);
        }
    }
    cout << ans << endl;
}

int main() {
    solve();
}