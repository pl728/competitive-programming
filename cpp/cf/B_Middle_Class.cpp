#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rev(i, a, b) for (int i = a; i >= b; i--)
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define v vector
using ll = long long;
using namespace std;

template <typename... T>
void see(T &...args) { ((cin >> args), ...); }

const int M = 1e9 + 7;
int grid[1005][1005] = {0};

void solve()
{
    int n, x;
    see(n, x);
    v<int> a(n);
    rep(i, 0, n) see(a[i]);
    sort(all(a), greater{});
    ll t = 0;
    rep(i, 0, n)
    {
        if ((t + a[i]) / (i + 1) < x)
        {
            cout << i << endl;
            return;
        }
        t += a[i];
    }

    cout << n << endl;
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
}