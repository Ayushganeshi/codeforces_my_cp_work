#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0);

//  AUTHOR:->Ayush Kumar Gupta 
//       !! CHESS & CODE!! 

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    int idx = -1;
    for (int i = 1; i + 1 < n; i++) {
        if (arr[i] > arr[i + 1] && arr[i] > arr[i - 1]) {
            idx = i;
            break;
        }
    }

    if (idx == -1) {
        cout << "NO" << '\n';
    } else {
        cout << "YES" << '\n';
        
        cout << idx << " " << idx + 1 << " " << idx + 2 << '\n';
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
