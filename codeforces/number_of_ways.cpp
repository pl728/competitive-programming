#include <bits/stdc++.h>
#define lli long long int
using namespace std;

// rating: 1700
// to compile:
// g++ -std=c++11 -O2 -Wall number_of_ways.cpp -o number_of_ways

int main()
{
    int n;
    cin >> n;
    lli a[n];
    unordered_map<lli, int> m;
    lli total_sum = 0;
    // leave index 0 empty
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        total_sum += a[i];
        if (i > 0 && i < n - 1)
        {
            if (m[total_sum])
            {
                m[total_sum]++;
            }
            else
            {
                m[total_sum] = 1;
            }
        }
    }
    lli num_ways = 0;

    if (total_sum % 3 == 0)
    {
        lli s1 = 0;
        for (int i = 0; i < n - 2; i++)
        {
            s1 += a[i];
            lli one_third = total_sum / 3;
            if (s1 == one_third && s1 != 2 * one_third)
            {
                if (m[2 * one_third])
                {
                    num_ways += m[2 * one_third];
                }
            }
            else if (s1 != one_third && s1 == 2 * one_third)
            {
                if (i > 0 && m[2 * one_third])
                    m[2 * one_third]--;
            }
            else if (s1 == one_third && s1 == 2 * one_third)
            {
                if (i > 0 && m[2 * one_third])
                    m[2 * one_third]--;
                if (m[2 * one_third])
                {
                    num_ways += m[2 * one_third];
                }
            }
            else
            {
            }
        }
    }

    cout << num_ways;
    return 0;
}