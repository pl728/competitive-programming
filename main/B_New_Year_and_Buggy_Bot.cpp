#include <bits/stdc++.h>
#define py puts("YES")
#define pn puts("NO")
#define pf puts("-1")
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rev(i, a, b) for (int i = a; i >= b; i--)
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define sz(x) ((int)(x).size())
#define v vector
using ll = long long;
using namespace std;

template <typename... T>
void see(T &...args) { ((cin >> args), ...); }

const int M = 1e9 + 7;
int grid[1005][1005] = {0};
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
string ds = "RLDU";

// [R,U,L,D]
void solve();
int main()
{
    solve();
}
void solve()
{
    int n, m;
    see(n, m);
    pair<int, int> start;
    pair<int, int> end;
    rep(i, 1, n + 1)
    {
        string s;
        see(s);
        rep(j, 0, sz(s))
        {
            grid[i][j + 1] = s[j];
            if (s[j] == 'S')
            {
                start.first = i;
                start.second = j + 1;
            }
            if (s[j] == 'E')
            {
                end.first = i;
                end.second = j + 1;
            }
        }
    }
    string d;
    see(d);
    // generate all permutations of 0,1,2,3
    v<v<int>> p;
    rep(i, 0, 4)
    {
        rep(j, 0, 4)
        {
            rep(k, 0, 4)
            {
                rep(l, 0, 4)
                {
                    if (i != j && i != k && i != l && j != k && j != l && k != l)
                    {
                        p.pb({i, j, k, l});
                    }
                }
            }
        }
    }
    int ans = 0;
    pair<int, int> pos = start;
    rep(i, 0, sz(p))
    {
        // move
        v<int> mapping = p[i];
        bool flag = true;
        rep(j, 0, (int)d.length())
        {
            if (pos != end)
            {
                pos.first += dx[mapping[d[j] - '0']];
                pos.second += dy[mapping[d[j] - '0']];
                if (pos.first < 1 || pos.first > n || pos.second < 1 || pos.second > m || grid[pos.first][pos.second] == '#')
                {
                    flag = false;
                    break;
                }
                // cout << pos.first << " " << pos.second << endl;
            }
            else
            {
                break;
            }
        }
        if (pos == end && flag)
        {
            // cout << pos.first << " " << pos.second << endl;
            ans++;
        }
        pos = start;
    }
    cout << ans << endl;
}