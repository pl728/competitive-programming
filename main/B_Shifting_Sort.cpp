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

int getLargest(v<int> x, int y)
{
    int largest = 0;
    rep(i, 0, y)
    {
        if (x[i] > x[largest])
            largest = i;
    }
    return largest;
}

void solve()
{
    int n;
    see(n);
    v<int> a(n);
    rep(i, 0, n) see(a[i]);
    v<string> ans;
    rev(i, a.size(), 1)
    {
        int largestIdx = getLargest(a, i);
        if (largestIdx == i - 1)
            continue;

        // shift largest, i to the left once
        int largest = a[largestIdx];
        rep(j, largestIdx, i)
        {
            a[j] = a[j + 1];
        }
        a[i - 1] = largest;
        string s = "";
        s += to_string(largestIdx + 1) + " " + to_string(i) + " " + to_string(1);
        ans.pb(s);
    }
    cout << ans.size() << endl;
    rep(i, 0, ans.size())
    {
        cout << ans[i] << " " << endl;
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