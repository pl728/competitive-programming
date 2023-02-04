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

void pvec(v<int> a)
{
    rep(i, 0, sz(a))
    {
        cout << a[i] << " ";
    }
    cout << "\n";
}

void solve()
{
    int n, c, ans;
    see(n, c);
    v<int> a(n);
    rep(i, 0, n) see(a[i]);
    v<int> b(n), x(n);
    rep(i, 0, n)
    {
        // 1 1 1 1 1
        // 1 2 3 4 5
        b[i] = i + 1 + a[i];
        x[i] = min(b[i], n + 1 - i + a[i]);
    }

    // for the first one, use b

    // for all the rest, use x

    auto it = min_element(all(b));
    int minIdx = distance(begin(b), it);
    pvec(x);
    pvec(b);
    x.erase(x.begin() + minIdx);
    cout << minIdx << endl;
    pvec(x);
    if (b[minIdx] >= c)
    {
        c -= b[minIdx];
        ans++;
    }
    else
    {
        cout << 0 << endl;
        return;
    }
    sort(all(x));
    rep(i, 0, n - 1)
    {
        if (c - x[i] < 0)
        {
            break;
        }
        c -= x[i];
        ans++;
    }
    cout << ans << endl;
}

void tie()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
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