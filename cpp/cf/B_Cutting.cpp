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
    int n, b;
    see(n,b);
    vi arr(n);
    read_array(arr);
    // debug(arr);

    multiset<int> cutCosts;
    int even=0;
    int odd=0;

    for(int i=0;i<n;i+=2) {
        if(arr[i]%2==0) {
            even++;
        } else {
            odd++;
        }
        if(arr[i+1]%2==1) {
            odd++;
        } else {
            even++;
        }
        if(i+2<n&&even==odd){
            cutCosts.insert(abs(arr[i+2]-arr[i+1]));
        }
    }
    // debug(cutCosts);
    int cuts = 0;

    for(auto it=cutCosts.begin();it!=cutCosts.end()&&b>=0;++it){
        if(b-*it<0){
            break;
        }
        b-=*it;
        cuts++;
    }
    cout << cuts << endl;
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
    solve();
}