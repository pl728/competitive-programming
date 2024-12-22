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

    // when next element is not negative, add it to our subarray
    // if the next element is negative, need to add it to our subarray
    // if next element by itself is larger than current sum + next element, start over
    for (lli i = 1; i < n; i++)
    {
        cin >> x[i];
        sum = max(x[i], sum + x[i]);
        best = max(sum, best);
    }

    cout << best;

    return 0;
}