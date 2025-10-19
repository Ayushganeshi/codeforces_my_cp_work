#include <bits/stdc++.h>
using namespace std;
#define int long long ;
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0);

//  AUTHOR:->Ayush Kumar Gupta 
//       !! CHESS & CODE!! 

void solve() {
    int n;
    cin >> n;
    
    int zeroes = 0, oones = 0;
    for (int i = 0; i < n; i++) {
        int x; 
        cin >> x;
        if (x == 0) zeroes++;
        else if (x == 1) ones++;
    }
    
    int total = ones * (1LL << zeroes);
    cout << total << "\n";
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

