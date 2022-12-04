#include <bits/stdc++.h>
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

void solve()
{
    int n, q;
    see(n, q);
    string s;
    see(s);
    int tabc = 0;
    rep(i, 0, n - 2)
    {
        if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c')
        {
            tabc++;
        }
    }
    // bcabccabc
    while (q--)
    {
        int x;
        char c;
        see(x, c);
        int abc1 = 0;
        rep(i, max(0, x - 3), min(n - 2, x))
        {

            if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c')
            {
                abc1++;
            }
        }
        s[x - 1] = c;
        int abc2 = 0;
        rep(i, max(0, x - 3), min(n - 2, x))
        {
            // cout << s[i] << s[i + 1] << s[i + 2] << endl;
            if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c')
            {
                abc2++;
                // cout << abc2 << endl;
            }
        }
        tabc += (abc2 - abc1);
        cout << tabc << endl;
        // cout << endl;
    }
}

int main()
{
    solve();
}