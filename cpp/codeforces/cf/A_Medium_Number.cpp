#include <bits/stdc++.h>
#define for(i,b) for (int i = 0; i < b; i++)
using ll = long long;
using namespace std;

const int M = 1e9 + 7;

void solve() {
    int a, b, c; cin >> a >> b >> c;
    vector<int> arr;
    arr.push_back(a);
    arr.push_back(b);
    arr.push_back(c);
    sort(arr.begin(), arr.end());
    cout << arr[1] << endl;

}

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
         solve();
    }
}