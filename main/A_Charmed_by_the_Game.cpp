#include <bits/stdc++.h>
#define py puts("YES")
#define pn puts("NO")
#define pf puts("-1")
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rev(i, a, b) for (int i = a; i >= b; i--)
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define sz(x) ((int)(x).size())
#define len(x) ((int)(x).length())
#define v vector
#define vi v<int>
#define vii v<v<int>>
#define contains(a, b) ((a).find(b) != (a).end())
using ll = long long;
using namespace std;

template <typename... T>
void see(T &...args) { ((cin >> args), ...); }

const int MXN = 1e9 + 7;
int grid[1005][1005] = {0};

void solve()
{
    int a, b;
    see(a, b);
    // serves alternate, if no breaks then abs(a-b) cannot be more than 1
    // if everyone holds serve, difference will never be more than 1
    //
    if (a == b)
    {
        cout << (a + b) / 2 + 1 << endl;
        for (int i = 0; i <= a + b; i += 2)
        {
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    else
    {
        // 3 1
        // up until 1-1, could be 0 breaks or 2 breaks
        // for 2-0, must be at 1 break
        //
        // 5 1
        // up until 1-1, could be 0 or 2
        // for 4-0, must be 2 breaks
        // 2, 4
        //
        // 4 1
        // up until 1-1, could be 0 or 2
        // for 3-0, must be 1 or two breaks
        // 1,2,3,4
        // formula:
        vi x;
        vi y;
        set<int> z;
        for (int i = 0; i <= 2 * min(a, b); i += 2)
        {
            x.pb(i);
        }
        y.pb(abs(a - b) / 2);
        if ((abs(a - b) & 1))
            y.pb(y[0] + 1);
        rep(i, 0, sz(y))
        {
            rep(j, 0, sz(x))
            {
                z.insert(y[i] + x[j]);
            }
        }
        cout << sz(z) << endl;
        for (int i : z)
        {
            cout << i << " ";
        }
        cout << endl;
        return;
    }
}

void tie()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void solve();
int main()
{
    tie();
    int tc;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
}