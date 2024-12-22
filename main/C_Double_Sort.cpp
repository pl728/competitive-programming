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

const int MXN = 1e9 + 7;
int grid[1005][1005] = {0};

void solve()
{
    int n;
    see(n);
    vi arr1(n), arr2(n);
    read_array(arr1), read_array(arr2);
    // debug(arr1); debug(arr2);
    vector<pair<int,int>> sol;

    rep(i,0,n) {
        rep(j,i+1,n) {
            if(arr1[i] > arr1[j]) {
                swap(arr1[i], arr1[j]);
                swap(arr2[i], arr2[j]);
                sol.push_back(make_pair(j+1,i+1));
            }
        }
    }
    // debug(arr1); debug(arr2);

    int x=0,y=1;
    while(x<n){
        while(y<n && arr1[y]==arr1[x]) {
            y++;
        }
        if(y!=x+1){
            rep(i,x,y) {
                rep(j,i+1,y) {
                    if(arr2[i]>arr2[j]){
                        swap(arr2[i], arr2[j]);
                        sol.push_back(make_pair(j+1,i+1));
                    }
                    
                }
            }
        }
        
        x=y;y=x+1;
    }

    // debug(arr1); debug(arr2);

    if(is_sorted(arr1.begin(), arr1.end()) && is_sorted(arr2.begin(),arr2.end())){
        cout << sz(sol) << endl;
        rep(i,0,sz(sol)){
            cout << sol[i].first << " " << sol[i].second << endl;
        }
    } else {
        cout << -1 << endl;
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