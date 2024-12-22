#include <bits/stdc++.h>
#define F(i,a,b) for (int i = a; i < b; i++)
#define ll long long;
using namespace std;

int main() {
    long long n; cin >> n;
    while(n != 1) {
        cout << n << " ";
        if(n & 1) {
            n = n * 3 + 1;
        } else {
            n /= 2;
        }
    }

    cout << n;
}