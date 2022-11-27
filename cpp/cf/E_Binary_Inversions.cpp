#include <bits/stdc++.h>
#define f(i,b) for (int i = 0; i < b; i++)
using ll = long long;
using namespace std;

// 1 0 1 0
// 2 2 1 1

const int M = 1e9 + 7;


ll calcInversions(vector<int> x) {
    int numZeroes = 0;
    ll numInversions = 0;
    int n = x.size();
    for(int i = n-1; i >= 0; i--) {
        if(x[i] == 0)  numZeroes++;
        else numInversions += numZeroes;
    }

    return numInversions;
}

void solve() {
    int n; cin >> n;
    // flip either the first zero or the last 1
    vector<int> a(n);
    f(i,n) {
        cin >> a[i];
    }
    int numZeroes = 0;
    ll numInversions = 0;
    for(int i = n-1; i >= 0; i--) {
        if(a[i] == 0)  numZeroes++;
        else numInversions += numZeroes;
    }

    int firstZero = -1, lastOne = -1;
    f(i,n) {
        if(a[i] == 0) {
            firstZero = i;
            break;
        } 
    }
    for(int i = n-1; i >= 0; i--) {
        if(a[i] == 1) {
            lastOne = i;
            break;
        }
    }
    if(firstZero == -1 || lastOne == -1) {
        // 1111 or 0000 -> 1110 or 1000
        cout << n-1 << endl;
        return;
    }
    vector<int> b = a, c = a;
    b[firstZero] = 1, c[lastOne] = 0;
    numInversions = max(numInversions, calcInversions(b));
    numInversions = max(numInversions, calcInversions(c));
    cout << numInversions << endl;
}

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
         solve();
    }
}