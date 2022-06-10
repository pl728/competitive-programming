#include <bits/stdc++.h>
#define lli long long int
using namespace std;

// given hc, dc, hm, dm, determine whether the char will win the fight
// how many turns? min(ceil(hc/dm), ceil(hm/dc))
// turns to kill human: ceil(hc/dm)
// turns to kill monster: ceil(hm/dc)
// if they are equal, the character wins due to first hit. 

bool spend_coins(lli h_c, lli d_c, lli h_m, lli d_m, int k, int w, lli a) {
    // human can't defeat monster, spend coins
    for(int i = 0; i < k + 1; i++) {
        int weapon_upgrade = i;
        int armor_upgrade = k - i;
        lli ttkh = ceil(float(h_c + armor_upgrade * a)/float(d_m));
        lli ttkm = ceil(float(h_m)/float(d_c + weapon_upgrade * w));

        if(ttkh >= ttkm) {
            return true;
        }

    }
    return false;
}

int main()
{
    int t;
    cin >> t; 
    int k, w;
    lli h_c, d_c, h_m, d_m, a;

    for(int x = 0; x < t; x++) {
        cin >> h_c >> d_c >> h_m >> d_m >> k >> w >> a;
        
        lli ttkh = ceil(float(h_c)/float(d_m));
        lli ttkm = ceil(float(h_m)/float(d_c));

        if(ttkh >= ttkm) {
            cout << "YES" << "\n";
        } else {
            if(spend_coins(h_c, d_c, h_m, d_m, k, w, a)) {
                 cout << "YES" << "\n";
            } else {
                cout << "NO" << "\n";
            }
        }
    }
    
    
    return 0;   
}
