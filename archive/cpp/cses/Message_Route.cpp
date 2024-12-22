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
    int n, m;
    see(n, m);
    v<v<int>> G(n + 1);
    v<int> visited(n + 1);
    v<int> from(n + 1);
    rep(i, 0, m)
    {
        int a, b;
        see(a, b);
        G[a].pb(b);
        G[b].pb(a);
    }
    // find the shortest path from 1 to n;
    // use BFS to find shortest path
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int x = q.front();
        if (x == n)
            break;
        q.pop();
        for (int y : G[x])
        {
            if (!visited[y])
            {
                visited[y] = 1;
                from[y] = x;
                q.push(y);
            }
        }
    }
    if (!visited[n])
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    int x = n;
    int c = 0;
    v<int> ans;
    while (x != 1)
    {
        c++;
        ans.pb(x);
        x = from[x];
    }
    cout << c + 1 << endl;
    ans.pb(1);
    rev(i, c, 0) cout << ans[i] << " ";
}

int main()
{
    solve();
}