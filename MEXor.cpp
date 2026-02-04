#include <bits/stdc++.h>
using namespace std;

#define int long long;


// AUTHOR:->Ayush 
//       !! CHESS & CODE 

void solve() {
    int mex,x;
    cin >> mex >> x;
?? for (int i=0;i<n;i++
)
    [
        

    
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








