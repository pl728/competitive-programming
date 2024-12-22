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
using ll = long long;
using namespace std;

template <typename... T>
void see(T &...args) { ((cin >> args), ...); }

const int M = 1e9 + 7;
int grid[1005][1005] = {0};

void solve();
int main()
{
    solve();
}
void solve()
{
    int n;
    see(n);
    string s;
    see(s);
    v<int> c[30];
    rep(i, 0, len(s))
    {
        c[s[i] - 'a'].pb(i);
    }
    // store the first occurrence of each letter
    int m;
    see(m);
    while (m--)
    {
        string nm;
        see(nm);
        int cnt[30];
        rep(i, 0, 26) cnt[i] = 0;
        rep(i, 0, len(nm)) cnt[nm[i] - 'a']++;
        int ans = -1;
        rep(i, 0, 26)
        {
            if (cnt[i])
                ans = max(ans, c[i][cnt[i] - 1]);
        }
        cout << ans + 1 << endl;
    }
}