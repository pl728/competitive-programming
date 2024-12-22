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
    string s;
    see(n, s);
    if (n == 1)
    {
        if (s[0] != 'W')
        {
            cout << "NO" << endl;
            return;
        }
        else
        {
            cout << "YES" << endl;
            return;
        }
    }
    int r = 0, b = 0, w = 0;
    rep(i, 0, n)
    {
        if (s[i] == 'W')
        {
            if ((!r && b) || (r && !b) || (r + b == 1))
            {
                cout << "NO" << endl;
                return;
            }
            w++;
            r = 0, b = 0;
        }
        else if (s[i] == 'R')
        {
            r++;
            w = 0;
        }
        else
        {
            b++;
            w = 0;
        }
    }
    if ((!r && b) || (r && !b) || (r + b == 1))
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
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