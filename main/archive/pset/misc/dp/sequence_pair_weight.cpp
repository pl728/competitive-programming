#include <bits/stdc++.h>
#define lli long long int
using namespace std;

// status: incomplete

// to compile:
// g++ -std=c++11 -O2 -Wall _.cpp -o _

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        int a[n];
        lli dp[n];
        lli dp_curr = 0;
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];

            if (m.find(a[i]) == m.end())
            {
                m[a[i]] = 0;
            }
            else
            {
                dp_curr += m[a[i]];
            }

            dp[i] = dp_curr;
            m[a[i]]++;
        }

        lli sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += dp[i];
        }

        cout << sum << "\n";
    }

    return 0;
}