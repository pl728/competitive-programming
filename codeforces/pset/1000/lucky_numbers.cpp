#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int main()
{
    int n; cin >> n;
    set<int> lucky = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777, };
    if(lucky.find(n) != lucky.end()) {
        cout << "YES";
        return 0;
    } else {
        for(auto it = lucky.begin(); it != lucky.end(); it++) {
            if(n % (*it) == 0) {
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";


    return 0;
}