#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int main()
{
    lli n;
    cin >> n;
    lli x[n - 1];
    lli best = 0, sum = 0;
    cin >> best;
    sum = best;

    // when next element is negative, add it to sum
    // if next element is larger than current sum, start over
    for (lli i = 1; i < n; i++)
    {
        cin >> x[i];
        sum = max(x[i], sum + x[i]);
        best = max(sum, best);
    }

    cout << best;

    return 0;
}