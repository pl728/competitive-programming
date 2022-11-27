#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int main()
{
    int s, n; cin >> s; cin >> n;
    int x[n], y[n];
    multimap<int, int> m;
    for(int i = 0; i < n; i++) {
        cin >> x[i]; cin >> y[i];
        m.insert({x[i], y[i]});
        
    }

    for(auto it = m.begin(); it != m.end(); it++) {
        if(s > (*it).first) {
            s += (*it).second;
        } else {
            cout << endl;
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}