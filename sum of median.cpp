#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0);

//  AUTHOR:->Ayush Kumar Gupta 
//       !! CHESS & CODE!! 

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n * k);
    for (int i = 0; i < n * k; i++) {
        cin >> arr[i];
    }

    int mid = (n + 1) / 2;
    int pos = n * k;
    int step = n - mid + 1;

    int sum = 0;
    while (k--) {
        pos -= step;
        sum += arr[pos];
    }

    cout << sum << '\n';
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
