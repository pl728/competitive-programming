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
    string s; see(s); int n=sz(s);
    vi replace(sz(s));
    fill(replace.begin(),replace.end(),0);

    if(sz(s)==1){
        cout<<s<<endl;
        return;
    }
    for(int i=0;i<10;i++){
        char c='0'+i;
        int lastOcc=-1;
        for(int j=n-1;j>=0;j--){
            if(lastOcc==-1){
                if(s[j]==c){
                    lastOcc=j;
                }
            } else if(s[j]>c) {
                replace[j]=1;
            }
        }
    }
    // debug(replace);
    multiset<int> bag;
    rep(i,0,n){
        if(replace[i]==1) {
            int xxx = s[i]-'0';
            bag.insert(min(9,xxx+1));
        } else {
            bag.insert(s[i]-'0');
        }
    }

    for(auto it = bag.begin(); it != bag.end(); it++) {
        cout << *it;
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