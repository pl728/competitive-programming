#include <bits/stdc++.h>
#define lli long long int
using namespace std;

// to compile:
// g++ -std=c++11 -O2 -Wall vanya_and_lanterns.cpp -o vanya_and_lanterns

int main()
{

    int n;
    lli l;
    cin >> n >> l;
    double a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n);

    double max_dist = a[0];

    for (int i = 1; i < n; i++)
    {
        max_dist = max(max_dist, (a[i] - a[i - 1]) / 2);
    }

    max_dist = max(max_dist, (l - a[n - 1]));

    std::cout << std::fixed;
    cout << setprecision(10);
    cout << (double)max_dist;

    return 0;
}