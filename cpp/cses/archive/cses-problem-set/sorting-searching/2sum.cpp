#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int main()
{
    int n; lli x;
    cin >> n >> x;
    lli a[n];
    unordered_map<lli, int> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(m.find(x - a[i]) != m.end()) {
            cout << i + 1 << " " << m[x - a[i]] + 1;
            return 0;
        }
        m.insert({a[i], i});
    }
    cout << "IMPOSSIBLE" << endl;


    return 0;
}