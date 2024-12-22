#include <bits/stdc++.h>
#define lli long long int
using namespace std;

// to compile:
// g++ -std=c++11 -O2 -Wall increasing_subsequence.cpp -o increasing_subsequence

int main()
{
    int n;
    cin >> n;
    vector<lli> x(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    // #================ n^2 solution ===============
    // lli dp[n];
    // dp[0] = 1;
    // for (int i = 1; i <= n; i++)
    // {
    //     dp[i] = 1;
    //     lli current_item = x[i];
    //     for (int j = 0; j < i; j++)
    //     {
    //         // find the largest item < the current item
    //         if (x[j] < current_item)
    //         {
    //             dp[i] = max(dp[i], dp[j] + 1);
    //         }
    //     }
    // }

    // cout << "\n";

    // cout << *max_element(dp, dp + n);

    // #================ n log n solution ===============
    vector<lli> dp;
    for (int i = 0; i < n; i++)
    {
        auto it = lower_bound(dp.begin(), dp.end(), x[i]);
        if (it == dp.end())
        {
            dp.push_back(x[i]);
        }
        else
        {
            (*it) = x[i];
        }
    }

    cout << dp.size();

    return 0;
}