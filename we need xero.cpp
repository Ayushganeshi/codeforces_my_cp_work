#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0);

//  AUTHOR:->Ayush Kumar Gupta 
//       !! CHESS & CODE!! 


void solve() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i <n; i++) {
        int x;
        cin >> x;
        ans ^= x;
    }

    if (n % 2 == 1) {
        cout << ans << '\n';
    } else if (ans == 0) {
        cout << 0 << '\n';
    } else {
        cout << -1 << '\n';
    }
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
