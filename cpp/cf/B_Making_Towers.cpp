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

    unordered_map<int, v<int>> idx;
    v<int> ans(n + 1);
    rep(i, 0, n) idx[a[i]].pb(i);
    // rep(i, 1, n + 1)
    // {
    //     rep(j, 0, idx[i].size())
    //     {
    //         cout << idx[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    rep(i, 1, n + 1)
    {
        if (idx[i].size() == 0)
        {
            cout << 0 << " ";
            continue;
        }
        int y = 1;
        int prev = idx[i][0];

        rep(j, 1, idx[i].size())
        {
            // if (((prev % 2 == 1) && (idx[i][j] % 2 == 0)) || ((prev % 2 == 0) && (idx[i][j] % 2 == 1)))

            if (((prev & 1) && !(idx[i][j] & 1)) || (!(prev & 1) && (idx[i][j] & 1)))
            {
                y++;
                prev = idx[i][j];
            }
        }
        cout << y << " ";
    }
    cout << endl;
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