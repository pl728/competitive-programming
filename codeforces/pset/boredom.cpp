#include <bits/stdc++.h>
#define lli long long int
using namespace std;

// to compile:
// g++ -std=c++11 -O2 -Wall _.cpp -o _

int main()
{
    int n;
    cin >> n;
    int next;
    int cnt[50001] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> next;
        cnt[i] += 1;
    }
    lli f[n + 1];
    f[0] = 0;
    f[1] = cnt[1];
    for (int i = 2; i < n + 1; i++)
    {
        f[i] = max(f[i - i], f[i - 2] + cnt[i] * i);
    }
    cout << f[n];
    return 0;
}