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
int a[2010][2010];
int cnt[2010];

void solve()
{
    int n;
    see(n);
    rep(i, 1, n + 1)
    {
        see(a[0][i]);
        cnt[a[0][i]]++;
    }
    rep(i, 1, n + 1)
    {
        rep(j, 1, n + 1)
        {
            a[i][j] = cnt[a[i - 1][j]];
        }
        fill(cnt, cnt + 2010, 0);
        rep(j, 1, n + 1) cnt[a[i][j]]++;
    }
    int q;
    see(q);
    while (q--)
    {
        int x, k;
        see(x, k);

        cout << a[min(n, k)][x] << endl;
    }
    fill(cnt, cnt + 2010, 0);
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