#include <bits/stdc++.h>
#define lli long long int
using namespace std;

// idea; try to create as many 4s, then 3s, then 2s, then 1s
// [0, 1, 1, 2, 1]
// 3 can only go with 1, or by itself
// 3 + 1, 2 + 2, 2 + 1, 1 + 1
// only dealing with groups of 1, 2, and 3
// try 3 and 1 first, and 2 and 2 first
int main()
{
    int n; cin >> n;
    int count[5] = {0};
    for(int i = 0; i < n; i++) {
        int next; cin >> next; count[next] += 1;
    }
    int taxis = count[4];
    count[4] = 0;
    // pairs of 2
    taxis += ceil((float) count[2] / 2);
    // match 3 and 1
    if(count[3] > count[1]) {
        taxis += count[1] + (count[3] - count[1]);
        count[1] = 0; count[3] = count[3] - count[1];
    } else {
        taxis += count[3] + ceil((float)(count[1] - count[3]) / 4);
        count[3] = 0; count[1] = count[1] - count[3];
    }
    if(count[1] = 0) {

    } else if (count[3] == 0) {

    }
    
    cout << taxis;
    

    return 0;
}