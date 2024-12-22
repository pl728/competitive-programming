#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int main()
{
    int n;
    lli x;
    cin >> n >> x;
    lli weights[n];

    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }
    sort(weights, weights + n);
    int count = 0;
    int i = 0, j = n - 1;
    while (j > i)
    {
        if (weights[i] + weights[j] <= x)
        {
            i++;
        }
        count++;
        j--;
    }
    if (j == i)
    {
        count++;
    }
    cout << count;

    return 0;
}