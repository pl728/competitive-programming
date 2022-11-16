#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int main()
{
    // ++, **, 
    // a+b*c, a*b+c, (a+b)*c, a+(b*c), (a*b)+c, a*(b+c)
    int a, b, c;
    cin >> a; cin >> b; cin >> c;
    int A[8] = {a+b*c, a*b+c, (a+b)*c, a+(b*c), (a*b)+c, a*(b+c), a+b+c, a*b*c};
    cout << *max_element(A, A + 8);
    return 0;
}