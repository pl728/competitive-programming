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
int grid[105][105] = {0};

void solve()
{
    int n, k;
    see(n, k);
    v<int> h(n);
    rep(i, 0, n) see(h[i]);
    // first element that is less than the next
    int ans;
    while (k--)
    {
        int x = 1;
        while (x < n && h[x] <= h[x - 1])
            x++;
        if (x == n)
        {
            cout << -1 << endl;
            return;
        }
        h[x - 1]++;
        ans = x - 1;
    }
    cout << ans + 1 << endl;
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