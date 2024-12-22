#include <bits/stdc++.h>
#define py puts("YES")
#define pn puts("NO")
#define pf puts("-1")
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rev(i, a, b) for (int i = a; i >= b; i--)
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define sz(x) ((int)(x).size())
#define len(x) ((int)(x).length())
#define v vector
#define vi v<int>
#define vii v<v<int>>
#define contains(a, b) ((a).find(b) != (a).end())
using ll = long long;
using namespace std;

template <typename... T>
void see(T &...args) { ((cin >> args), ...); }

const int MXN = 1e9 + 7;
int grid[1005][1005] = {0};

int sd(int n)
{
    int s = 0, m;
    while (n > 0)
    {
        m = n % 10;
        s = s + m;
        n = n / 10;
    }
    return s;
}
void solve()
{
    int n, q;
    see(n, q);
    // cout << n << " " << q << endl;

    v<int> a(n + 1);
    rep(i, 0, n)
    {
        see(a[i + 1]);
        // cout << a[i] << " ";
    }
    // cout << endl;

    rep(i, 0, q)
    {
        int xx;
        see(xx);
        // cout << xx << " ";
        if (xx == 1)
        {
            int l, r;
            see(l, r);
            // cout << l << " " << r << endl;
            rep(xxx, l, r + 1)
            {
                a[xxx] = sd(a[xxx]);
            }
        }
        else if (xx == 2)
        {
            int x;
            see(x);
            // cout << x << endl;
            printf("%d\n", a[x]);
        }
    }
}

void tie()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

void solve();
int main()
{
    tie();
    int tc;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
}