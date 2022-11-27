#include <bits/stdc++.h>
#define f(i,b) for (int i = 0; i < b; i++)
#define pb push_back
using ll = long long;
using namespace std;

const int M = 1e9 + 7;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int grid[1005][1005] = {0};
int visited[1005][1005] = {};
int n, m;

bool possible(int x, int y) {
    return x<n&&x>=0&&y<m&&y>=0;
}

void dfs(int x, int y) {
    if(!possible(x, y) || visited[x][y] == 1) return;
    if(grid[x][y] == 1) {
        visited[x][y] = 1;
        grid[x][y] = 0;
        f(i,4) {
            dfs(x + dx[i], y + dy[i]);
        }
    }
}

void solve() {
    cin >> n >> m;
    f(i,n) {
        string s; cin >> s;
        f(j, m) {
            if(s[j] == '#') grid[i][j] = 0;
            else grid[i][j] = 1;
        }
    }
    int ans = 0;
    f(i,n) {
        f(j,m) {
            if(grid[i][j]) {
                dfs(i,j);
                ans++;
            }
        }
        
    }
    cout << ans << endl;
}

int main() {
    solve();
}