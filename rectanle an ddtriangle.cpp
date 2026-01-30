#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast_io( ios_base::sync_with_stdio(0); cin.tie(0);

//  AUTHOR:->Ayush Kumar Gupta 
//       !! CHESS & CODE!! 




void solve() {
    int w, h;
    cin >> w >> h;
    
    int n, area = 0;
    
    for (int j = 0; j < 4; j++) {
        cin >> n;
        int s, e;
        for (int i = 0; i < n; i++) {
            int t;
            cin >> t;
            if (i == 0) s = t;
            if (i == n - 1) e = t;
        }
        if (j < 2) {
            area = max(area, (e - s) * h);
        } else {
            area = max(area, (e - s) * w);
        }
    }
    
    cout << area << "\n";
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



