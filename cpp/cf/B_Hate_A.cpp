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
    int n = s.length();
    int x = 0, y = 0;
    rep(i, 0, n)
    {
        if (s[i] == 'a')
            x++;
        else
            y++;
    }
    if (y == 0)
    {
        cout << s << endl;
        return;
    }
    if ((y & 1))
    {
        cout << ":(" << endl;
    }
    else
    {
        int z = 0;
        int i = 0;
        string t = "";
        while (i < n)
        {
            if (s[i] != 'a')
            {
                z++;
                t += s[i];
            }
            if (z == y / 2)
            {
                break;
            }
            i++;
        }
        if (t == s.substr(s.length() - t.length(), s.length()))
        {
            cout << s.substr(0, s.length() - t.length());
        }
        else
        {
            cout << ":(" << endl;
        }
    }
}

int main()
{
    solve();
}