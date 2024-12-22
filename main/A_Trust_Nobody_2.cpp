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

template <typename Iterable>
void debug(const Iterable& container, const string& prefix = "[", const string& separator = ", ", const string& suffix = "]\n") {
    cout << prefix;
    for (auto it = container.begin(); it != container.end(); ) {
        cout << *it;
        if (++it != container.end()) cout << separator;
    }
    cout << suffix;
}

void read_array(vi &v) {
    for (auto& element : v) {
        see(element);
    }
}

void solve()
{
    int n; see(n);
    vi A(n); read_array(A);
    rep(i,0,n+1){
        int x=0; int y=0;
        rep(j,0,n){
            if(A[j]>i)x++;
            else y++;
        }

        if(x==i) {
            cout << x << endl;
            return;
        }

        x=0;y=0;
    }

    cout << -1<< endl;
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