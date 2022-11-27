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
    int n, k;
    see(n, k);
    string s;
    see(s);

    v<int> stars;
    rep(i, 0, n)
    {
        if (s[i] == '*')
            stars.pb(i);
    }

    if (stars.size() < 3)
    {
        cout << stars.size() << endl;
        return;
    }
    int prev = stars[0];
    int ans = 0;
    rep(i, 2, stars.size() - 1)
    {
        if (stars[i] - prev > k)
        {
            ans++;
            prev = stars[i - 1];
        }
    }
    if (stars[stars.size() - 1] - prev > k)
    {
        ans++;
    }
    cout << ans + 2 << endl;
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