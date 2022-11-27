#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int main()
{
    int t;
    cin >> t;
    vector<pair<lli, lli>> v;
    for (int i = 0; i < t; i++)
    {
        lli a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    for (int i = 0; i < t; i++)
    {
        pair<lli, lli> cur = v.at(i);
        // (1, 1) -> 1 = 1
        // (2, 2) -> 1 + 2 = 1 + 2*1= 3
        // (3, 3) -> 1 + 2 + 4 = 1 + 2*1 + 2*2 = 7
        // (4, 4) => 1 + 2 + 4 + 6 = 1 + 2*1 + 2*2 + 2*3 = 13
        if (cur.first == cur.second)
        {
            cout << 1 + (cur.first - 1) * (cur.first) << "\n";
        }
        else if (cur.first < cur.second)
        {
            if (cur.second % 2 == 1)
            {
                cout << cur.second * cur.second - (cur.first - 1) << "\n";
            }
            else
            {
                cout << (cur.second - 1) * (cur.second - 1) + 1 + (cur.first - 1) << "\n";
            }
        }
        else if (cur.first > cur.second)
        {
            if (cur.first % 2 == 0)
            {
                // even
                cout << cur.first * cur.first - (cur.second - 1) << "\n";
            }
            else
            {
                // odd
                cout << (cur.first - 1) * (cur.first - 1) + 1 + (cur.second - 1) << "\n";
            }
        }
    }
}
