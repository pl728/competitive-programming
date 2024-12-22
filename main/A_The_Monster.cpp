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
    int a, b, c, d;
    see(a, b, c, d);
    int ans = M;
    rep(i, 0, 100)
    {
        rep(j, 0, 100)
        {
            if (d + c * i == b + a * j)
            {
                ans = min(ans, d + c * i);
            }
        }
    }
    if (ans == M)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }
}

int main()
{
    solve();
}