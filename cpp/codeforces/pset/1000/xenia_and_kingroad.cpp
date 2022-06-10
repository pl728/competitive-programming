#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int main()
{
    int n, m; cin >> n; cin >> m;
    int prev = 1;
    int current; cin >> current;
    lli t = current - prev;
    for(int i = 1; i < m; i++) {
        prev = current;
        cin >> current;
        if(prev < current) {
            t += (current - prev);
        } else if (prev > current) {
            t += current + (n - prev);
        }
    }
    cout << t;
    return 0;
}