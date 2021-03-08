#include <bits/stdc++.h>
#define lli long long int
using namespace std;

// to compile:
// g++ -std=c++11 -O2 -Wall _.cpp -o _

int main()
{
    int n;
    cin >> n;
    int x[n];
    int total_mod2 = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
        total_mod2 += x[i] % 2;
    }
    if (total_mod2 == 1)
    {
        // only one odd
        for (int i = 0; i < n; i++)
        {
            if (x[i] % 2 == 1)
            {
                cout << i + 1;
                break;
            }
        }
    }
    else
    {
        // only one even
        for (int i = 0; i < n; i++)
        {
            if (x[i] % 2 == 0)
            {
                cout << i + 1;
                break;
            }
        }
    }

    return 0;
}