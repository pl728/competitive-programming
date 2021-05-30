#include <bits/stdc++.h>
#define lli long long int
using namespace std;

// to compile:
// g++ -std=c++11 -O2 -Wall gcd_sum.cpp -o gcd_sum

int gcd(lli x, int y)
{
    // guaranteed to return 1, bottom line
    for (int i = y; i > 1; i--)
    {
        if (x % i == 0 && y % i == 0)
        {
            return i;
        }
    }
    return 1;
}

int x_sum(lli x)
{
    int m, sum = 0;
    while (x > 0)
    {
        m = x % 10;
        sum = sum + m;
        x = x / 10;
    }
    return sum;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        lli x;
        cin >> x;
        int xsum = x_sum(x);
        int g = gcd(x, xsum);
        // cout << "xsum: " << xsum << ", gcd: " << g << "\n";
        while (g == 1)
        {
            x += 1;
            xsum = x_sum(x);
            g = gcd(x, xsum);
            // cout << "xsum: " << xsum << ", gcd: " << g << "\n";
        }
        cout << x << "\n";
    }
    return 0;
}