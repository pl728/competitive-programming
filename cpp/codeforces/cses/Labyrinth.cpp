#include <bits/stdc++.h>
#define f(i,b) for (int i = 0; i < b; i++)
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define v vector

using ll = long long;
using namespace std;

const int M = 1e9 + 7;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
string ds="RLDU";
int grid[1005][1005] = {0};
int vis[1005][1005] = {0};
int n, m;

bool gridContains(int x, int y) {
    return x<n && x>=0 && y<m && y>=0;
}

void solve() {
    cin >> n >> m;
    int startx = -1, starty = -1;
    int endx = -1, endy = -1;
    string ans = "";
    f(i,n){
        string s; cin >> s;
        f(j,m) {
            if(s[j] == '#') grid[i][j] = '1';
            else if(s[j] == 'A') {
                grid[i][j] = '1';
                startx = i, starty = j;
            }
            else if(s[j] == 'B'){
                grid[i][j] = '2';
                endx = i, endy = j;
            }
            else grid[i][j] = '0';
        }
    }

    // BFS until reach B.
    // 
    char ch[1005][1005];
    vector<pair<int,int>> from[n+1][m+1];
    // from[startx][starty].push_back({0,0});
    queue<pair<int,int>> q;
    q.push({startx, starty});
    while(!q.empty()) {
        pair<int,int> next = q.front();
        int x = next.first, y = next.second;
        q.pop();

        if(grid[x][y] == 'B') break;
        vis[x][y] = 1;
        f(i,4){
            int mx = x+dx[i], my = y + dy[i];
            if(!gridContains(mx, my)) continue;
            if(vis[mx][my] == 1 || grid[mx][my] == '1') continue;
            
            vis[mx][my] = 1;
            ch[mx][my] = ds[i];
            from[mx][my].push_back({x, y});
            q.push({x+dx[i], y+dy[i]});
        }
    }
    if(vis[endx][endy] == 0) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    string answer = "";
    // int a = endx, b = endy;
    // while(a != startx || b != starty) {
    //     answer += ch[a][b];
    //     a = from[a][b][0].first;
    //     b = from[a][b][0].second;
    // }
    pair<int,int> p = {endx, endy};
    while(p.first != startx || p.second != starty) {
        answer += ch[p.first][p.second];
        p = from[p.first][p.second][0];
    }
    reverse(all(answer));
    cout << answer.size() << endl;
    cout << answer << endl;
}

int main() {
    solve();
}