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
int visited[1005][1005] = {0};

void solve()
{
    int n;
    see(n);
    v<int> a(n);
    rep(i, 0, n) see(a[i]);
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    ll ps = 0;
    int ans = n;
    rep(i, 0, n)
    {
        ps += a[i];
        ll x = 0;
        int maxThick = 0;
        int thick = 0;
        rep(j, i + 1, n)
        {
            // cout << ans << endl;
            x += a[j];
            thick++;
            if (x > ps)
            {
                break;
            }
            if (x == ps)
            {
                maxThick = max(maxThick, thick);
                x = 0;
                thick = 0;
            }
        }
        if (x == 0 && maxThick != 0)
        {
            ans = min(ans, max(maxThick, i + 1));
        }
    }
    cout << ans << endl;
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