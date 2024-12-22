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
    int n;
    see(n);
    v<int> a(n);
    // 10 -> 01010
    // 20 -> 10100
    // 30 -> 11110
    rep(i, 0, n)
    {
        see(a[i]);
    }

    rep(i, 0, (1 << n))
    {
        ll x = 0;
        rep(j, 0, n)
        {
            if ((i & (1 << j)))
            {
                x += a[j];
            }
            else
            {
                x -= a[j];
            }
        }
        if (!(x % 360))
        {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main()
{
    solve();
}