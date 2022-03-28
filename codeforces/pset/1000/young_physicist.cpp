#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int main()
{
    int n; cin >> n;
    int s[3] = {0};

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            int next; cin >> next;
            s[j] += next;
        }
        
    }

    for(int i = 0; i < 3; i++) {
        if(s[i] != 0) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";

    return 0;
}