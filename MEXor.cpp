#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0);

// AUTHOR:->Ayush Kumar Gupta 
//       !! CHESS & CODE!!

void solve() {
    int mex,x;
    cin >> mex >> x;

    int c = 0;

    
    int xor_all = 0;
    int rem = (mex - 1) % 4;
    if (rem == 0) xor_all = (mex - 1);
    else if (rem == 1) xor_all = 1;
    else if (rem == 2) xor_all   = (mex - 1) + 1;
    else xor_all = 0;

    int temp = xor_all ^ x;
    int ans = 0;
    
    if (xor_all == x) ans = mex;
    else if (temp == mex) ans = mex + 2;
    else ans = mex + 1;

    cout << ans <<endl;
}

int32_t main() {
    fast_io();
    
    int t; 
    cin >> t;  
    while (t--) {
        solve();
    }

    return 0;
}

