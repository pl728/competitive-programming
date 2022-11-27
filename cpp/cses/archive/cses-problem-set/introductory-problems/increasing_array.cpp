#include <bits/stdc++.h>
#define lli long long int

using namespace std;

int main()
{
    lli n;
    cin >> n;
    lli x[n];
    for (lli i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    lli moves = 0, current = x[0];
    for (lli i = 1; i < n; i++)
    {

        moves += max(0LL, x[i - 1] - x[i]);
        if (x[i - 1] > x[i])
            x[i] = x[i - 1];
    }
    cout << moves;
    return 0;
}