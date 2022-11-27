#include <bits/stdc++.h>
#define lli long long int
using namespace std;

bool isPalindrome(string s) {
    string rev_s(s);
    reverse(rev_s.begin(), rev_s.end());
    return rev_s == s;
}

int main()
{

    int t;
    cin >> t;
    for(int x = 0; x < t; x++) {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        if(isPalindrome(s) || k == 0) {
            cout << 1 << "\n";
        } else {
            cout << 2 << "\n";
        }

    }   

    return 0;
}