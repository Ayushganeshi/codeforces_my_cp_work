#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast_io() ios_base::sync_with_stdio(0); cin.tie0);

//  AUTHOR:->Ayush Kumar Gupta 
//       !! CHESS & CODE!! 

void solve() {
    int n, p;
    cin >> n >> p;
    vector<int> a(n), b(n);
    vector<pair<int, int>>v(n)

    for (int i = 0; i < n; i++) cin >> a [i];
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        v.push_back({b[i], a[i]});
    }

    sort(v.begin(), v.end());
    int k = n, i = 0, cost = 0;
    cost += p;
    k--;

    while (i < n) {
        if (k == 0 || v[i].first > p) break;
        int left = min(k, v[i].second);
        cost += left * v[i].first;
        k -= left;
        i++;
    }

    if (k > 0) cost += k * p;
    cout << cost <<endl;
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



