#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0);

//  AUTHOR:->Ayush Kumar Gupta 
//       !! CHESS & CODE!! 

void solve() {
    int n, x;
    cin >> n>> x;

    int sum = 0, mini = 0;
    for (int i = 0; i < n; i++) {
        int a; 
        cin >> a;
        sum += a;
        if (a % x == 0) 
            mini += a / x;
        else 
            mini += (a / x) + 1;
    }

    int maxi = (sum % x == 0) ? (sum / x) : (sum / x + 1);
    cout << maxi << " " << mini << "\n";
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

