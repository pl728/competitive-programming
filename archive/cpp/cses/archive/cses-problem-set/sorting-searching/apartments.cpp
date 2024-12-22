#include <bits/stdc++.h>

#define lli long long int
using namespace std;

int main()
{

    int n, m;
    lli k;
    cin >> n >> m >> k;
    lli a[n];
    lli b[m];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    sort(a, a + n);
    sort(b, b + m);
    int i = 0, j = 0, count = 0;
    while (i < n && j < m)
    {
        if (a[i] <= b[j] + k && a[i] >= b[j] - k)
        {
            count++;
            i++;
            j++;
        }
        else if (a[i] > b[j])
        {
            j++;
        }
        else if (a[i] < b[j])
        {
            i++;
        }
    }
    cout << count;

    return 0;
}