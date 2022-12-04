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
    int q, d;
    see(q, d);
    while (q--)
    {
        int x;
        see(x);
        if (x >= 10 * d)
        {
            cout << "YES" << endl;
        }
        else
        {
            bool flag = 0;
            while (x >= d)
            {
                if (x % 10 == d)
                {
                    flag = 1;
                    break;
                }
                x -= d;
            }
            if (flag)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
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