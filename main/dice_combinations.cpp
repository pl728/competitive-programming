#include <bits/stdc++.h>
#define lli long long int
using namespace std;
#define MOD 1000000007

// to compile:
// g++ -std=c++11 -O2 -Wall _.cpp -o _

int main()
{
    int n;
    cin >> n;
    unordered_map<int, lli> m;
    m[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        lli current_ways = 0;
        for (int j = 1; j < 7; j++)
        {
            if (m.find(i - j) != m.end())
            {
                // if the key is in the map
                current_ways += m[i - j] % MOD;
            }
        }
        m[i] = current_ways % MOD;
    }
    cout << m[n];

    return 0;
}