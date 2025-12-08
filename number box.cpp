#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include <D:\CP\debug_Template.cpp>
#else
#define debug(..
#define debugArr(...)
#endif

using namespace std;

#define int long long
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0);
#define gcd __gcd
#define ull   unsigned long long

//  AUTHOR:->Ayush Kumar Gupta 
//       !! CHESS & CODE!! 

void solve() {
    int m, n;
    cin >> m >> n;
    vector<int> arr(m * n);
    int count = 0, sum = 0, mini = INT_MAX;

    for (int i = 0; i < m * n; i++) {
        cin >> arr[i];
        if (arr[i] <= 0) count++;
        sum += abs(arr[i]);
        arr[i] = abs(arr[i]);
        mini = min(mini, arr[i]);
    }

    if (count == 0 || count % 2 == 0) {
        cout << sum << endl;
    } else {
        sum -= 2 * mini;
        cout << sum << endl;
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



