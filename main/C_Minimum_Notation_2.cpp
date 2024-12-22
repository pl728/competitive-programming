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
    string s; see(s);
    int n=sz(s);
    vi a(n);
    rep(i,0,n){
        a[i]=s[i]-'0';
    }
    // debug(a);
    vi mn(n+1,9);
    for(int i=n-1;i>=0;i--){
        // want to find the smallest digit after each position
        mn[i]=min(mn[i+1],a[i]);
    }
    vi buff(10, 0);
    string ans = "";
    string t="0123456789";
    // debug(mn);
    rep(i,0,n){
        rep(j,0,mn[i]) {
            while(buff[j]){ 
                buff[j]--;
                ans+=t[j];
            }
        }
        if(a[i]==mn[i]){
            ans+=t[a[i]];
        } else {
            buff[min(9,a[i]+1)]++;
        }
        
    }
    rep(i,0,10){
        while(buff[i]){
            buff[i]--;
            ans+=t[i];
        }
    }

    cout << ans << endl;
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