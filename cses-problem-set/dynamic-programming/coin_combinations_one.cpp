#include <bits/stdc++.h>
#define lli long long int
using namespace std;

// to compile:
// g++ -std=c++11 -O2 -Wall minimizing_coins.cpp -o minimizing_coins

int main()
{
    lli n, x;
    cin >> n >> x;
    lli coins[n];
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    // ###############################
    lli dp[x + 1];
    dp[0] = 0;
    for (int i = 0; i <= x; i++)
    {
        dp[i] = 1e10;
        for (auto c : coins)
        {
            if (i - c >= 0)
            {
                dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }
    }
    // if (dp[x] == 1e10)
    //     cout << "-1";
    // else
    //     cout << dp[x];

    
    return 0;
}
