#include <bits/stdc++.h>
#define F(i,a,b) for (int i = a; i < b; i++)
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    int allNumbers[n*m];
    F(i,0,n) {
        F(j,0,m) {
            cin >> allNumbers[i*m + j];
        }
    }
    sort(allNumbers, allNumbers + n*m);

    // F(i,0,n*m) {
    //     cout << allNumbers[i] << " ";
    // }
    // cout << endl;

    int a = 0;
    int b = min(n,m);
    F(i,0,n) {
        F(j,0,m) {
            if(i == j) {
                cout << allNumbers[a++] << " ";
            } else {
                cout << allNumbers[b++] << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
         solve();
    }
}