#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int main()
{
    int t;
    cin >> t;
    int x[t];
    for(int i = 0; i < t; i++) {
        cin >> x[i];
        if(x[i] % 7 == 0) {
            cout << x[i] << "\n";
        } else {
            int y = x[i] -x[i] % 10;
            for(int j = 0; j < 10; j++) {
                if((y + j) % 7 == 0) {
                    cout << y + j << "\n";
                    break;
                }
            }
        }
    }

    return 0;
}