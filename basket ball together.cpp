#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast_io() ios_base::sync_with_stdio(0); 

//  AUTHOR:->Ayush Kumar Gupt
//       !! CHESS & CODE!! 


void solve() {
    int n, d;
    cin >> n >> d;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int i = 0, j = n - 1;
    int ans = 0;
    while (i <= j) {
        int p = arr[j];
        int need = d / p;
        if (need * p <= d) need++;
        i += (need - 1);
        if (i <= j) ans++;
        else break;
        j--;
    }
    cout << ans << "\n";
}

int32_t main() {
    fast_io();
    
    int t = 1; 
    //cin >> t;  
    while (t--) {
        solve();
    }

    return 0;
}


