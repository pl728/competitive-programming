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
    rev(i, n - 2, -1)
    {
        if ((s[i] - '0') + (s[i + 1] - '0') >= 10)
        {
            int x = (s[i] - '0') + (s[i + 1] - '0');
            rep(j, 0, n)
            {
                if (j != i && j != i + 1)
                    cout << s[j];
                else
                {
                    cout << x;
                    j++;
                }
            }
            cout << endl;
            return;
        }
    }
    cout << (s[0] - '0') + (s[1] - '0');
    rep(i, 2, n) cout << (s[i] - '0');
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