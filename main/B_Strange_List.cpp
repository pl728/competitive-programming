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
    v<int> b(n);
    ll t = 0;
    rep(i, 0, n)
    {
        see(a[i]);
        t += a[i];
    }
    b = a;
    while (1)
    {
        rep(i, 0, n)
        {
            if (b[i] % x == 0)
            {
                b[i] = b[i] / x;
                t += a[i];
                // rep(i, 0, n) cout << b[i] << " ";
                // cout << endl;
            }

            else
            {
                cout << t << endl;
                return;
            }
        }
    }
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