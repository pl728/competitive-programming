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
    string s;
    see(s);
    int ones = 0;
    rep(i, 0, s.length())
    {
        if (s[i] == '1')
            ones++;
    }
    if (ones == 0 || ones == s.length())
    {
        cout << s << endl;
        return;
    }
    string ans = "";
    ans += s[0];
    rep(i, 1, s.length())
    {
        if (s[i - 1] - '0')
        {
            if (s[i] - '0')
                ans += '0';
        }
        else
        {
            if (s[i] - '0' == 0)
                ans += '1';
        }
        ans += s[i];
    }
    cout << ans << endl;
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