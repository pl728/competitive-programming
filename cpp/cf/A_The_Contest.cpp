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
    ll t = 0;
    rep(i, 0, n)
    {
        see(a[i]);
        t += a[i];
    }

    int m;
    see(m);
    v<int> l(m);
    v<int> r(m);

    rep(i, 0, m)
    {
        see(l[i], r[i]);
    }
    rep(i, 0, m)
    {
        if (r[i] >= t && l[i] <= t)
        {
            cout << t << endl;
            return;
        }
        else if (l[i] > t)
        {
            cout << l[i] << endl;
            return;
        }
    }

    cout << -1 << endl;
    return;
}

int main()
{
    solve();
}