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

void solve()
{
    string s;
    see(s);
    // the thief cannot come after a 0
    // thief cannot come before a 1
    // int x = 0, y = 0, z = 0;
    int lastOne = -1, firstZero = -1;
    rep(i, 0, (int)s.length())
    {
        if (s[i] == '0')
        {
            if (firstZero == -1)
                firstZero = i;
        }
        if (s[i] == '1')
        {
            lastOne = i;
        }
    }
    if (firstZero == -1 && lastOne == -1)
    {
        cout << s.length() << endl;
        return;
    }
    if (firstZero == -1)
    {
        cout << s.length() - lastOne << endl;
        return;
    }
    if (lastOne == -1)
    {
        cout << firstZero + 1 << endl;
        return;
    }
    cout << firstZero - lastOne + 1 << endl;
    return;
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