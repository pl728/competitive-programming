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
    int n, k;
    see(n, k);
    string(s);
    see(s);
    vi x, y;
    rep(i, 0, len(s))
    {
        if (s[i] == '0')
            x.pb(i);
        else
            y.pb(i);
    }
    vi z(n, 0);
    if (k & 1)
    {
        // flip as many ones as possible
        //
        int i = 0;
        while (i < sz(y) && i + 1 < sz(y) && k >= 2)
        {
            k -= 2;
            s[y[i]] = '0';
            s[y[i + 1]] = '0';
            z[y[i]]++;
            z[y[i + 1]]++;
            i += 2;
        }
        if ((sz(y) & 1) && k >= 3)
        {
            swap(s[y[i]], s[n - 1]);
            z[y[i]]++, z[n - 1]++;
            i++;
            k -= 2;
        }
        int firstOne = n - 1;
        rep(i, 0, len(s))
        {
            if (s[i] == '1')
            {
                firstOne = i;
                break;
            }
        }
        rep(i, 0, len(s))
        {
            if (i != firstOne)
            {
                if (s[i] == '0')
                {
                    s[i] = '1';
                }
                else
                {
                    s[i] = '0';
                }
            }
        }
        k--;
        z[0] += k;
    }
    else
    {
        int i = 0;
        while (i < sz(x) && i + 1 < sz(x) && k >= 2)
        {
            k -= 2;
            s[x[i]] = '1';
            s[x[i + 1]] = '1';
            z[x[i]]++;
            z[x[i + 1]]++;
            i += 2;
        }
        if ((sz(x) & 1) && k >= 2)
        {
            swap(s[x[i]], s[n - 1]);
            z[x[i]]++, z[n - 1]++;
            k -= 2;
        }
        z[0] += k;
    }
    cout << s << endl;
    rep(i, 0, n)
    {
        cout << z[i] << " ";
    }
    cout << endl;
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