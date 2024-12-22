#include <bits/stdc++.h>
#define F(i,a,b) for (int i = a; i < b; i++)
using namespace std;

void solve() {
    ifstream cin ("speeding.in");
    ofstream cout ("speeding.out");

    int N, M;
    cin >> N >> M;
    vector<int> roadX(N);
    vector<int> roadY(N);
    F(i,0,N) {
        int x, y;
        cin >> x >> y;
        roadX[i] = x;
        roadY[i] = y;
    }

    int currentRoad = 0;
    int maxAbove = 0;
    F(i,0,M) {
        int x, y;
        cin >> x >> y;
        while(x > 0 && x >= roadX[currentRoad]) {
            maxAbove = max(maxAbove, y - roadY[currentRoad]);
            x -= roadX[currentRoad];
            currentRoad++;
        }
        if(x > 0) {
            maxAbove = max(maxAbove, y - roadY[currentRoad]);
            roadX[currentRoad] -= x;
        }
    }
    
    cout << maxAbove << endl;
}

int main() {
    solve();
}