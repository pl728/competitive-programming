#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int main()
{
    int n, t;
    cin >> n; cin >> t;
    int a[n];
    a[0] = 0;
    for(int i = 1; i < n; i++) {
        cin >> a[i];
    }

    deque<int> q;
    q.push_back(1);
    while(!q.empty()) {
        int next = q.front();
        q.pop_front();
        if(next > t) {
            cout << "NO";
            return 0;
        } else if(next == t) {
            cout << "YES";
            return 0;
        }
        q.push_back(next + a[next]);
    }

    return 0;
}