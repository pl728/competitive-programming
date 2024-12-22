#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    multiset<lli> ms;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        ms.insert(t);
    }
    // lli tickets[n], customers[m];
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        // iterator points to first item greater than x;
        auto it = ms.upper_bound(x);

        if (it == ms.begin())
        {
            // all ticket prices are greater
            cout << -1 << " ";
        }
        else
        {
            // use prev to reverse the iterator so that it points to
            // the first item less than x
            cout << *prev(it) << "\n";
            ms.erase(prev(it));
        }
    }
    return 0;
}