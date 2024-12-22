#include <bits/stdc++.h>
#define lli long long int
using namespace std;

// number of trailing zeros is equal to the number of 5s in its prime factorization. but numbers like 25, 125 contain more than 1 5 in its factorization. so the fomula is n/5 + n/25 + n/125 + ... 

int main()
{
    lli n;
    cin >> n;
    lli total_trailing = 0;
    int divisor = 5;
    while(divisor <= n) {
        total_trailing += n / divisor;
        divisor *= 5;
    }

    cout << total_trailing;


    return 0;
}