#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0);

//  AUTHOR:->Ayush Kumar Gupta 
//       !! CHESS & CODE!! 

class cmp {
public: 
    bool operator()(pair<int, int> &p1, pair<int, int> &p2) {
        int a = p1.first, b = p1.second;
        int c = p2.first, d = p2.second;
        if (a != c) return a > c;
        else return b < d;
    }
};

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    vector<pair<int, int>> p;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] >= k) {
            if (arr[i] % k == 0)
                arr[i] = k;
            else
                arr[i] %= k;
        }
        p.push_back({arr[i], i});
    }

    sort(p.begin(), p.end(), cmp());

    for (auto &c : p)
        cout << c.second + 1 << " ";
    cout <<endl;
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
