#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0);

//  AUTHOR:->Ayush Kumar Gupta 
//       !! CHESS & CODE!! 

void solve() {
    int f1x37;
    cin >> f1x37;

    vector<int> a1x(f1x37), pm9x(f1x37), ps9x(f1x37);

    for (int i = 0; i < f1x37; i++) {
        cin >>a1x[i];
    }

    pm9x[0] = a1x[0];
    ps9x[0] = pm9x[0];

    for (int i = 1; i < f1x37; i++) {
        if (pm9x[i - 1] < a1x[i]) {
            pm9x[i] = pm9x[i - 1];
        } else {
            pm9x[i] = a1x[i];
        }
        ps9x[i] = ps9x[i - 1] + pm9x[i];
    }

    int res5 = ps9x[f1x37 - 1];
    const int INF9 = 4e1;

    for (int i = 0; i < f1x37 - 1; i++) {
        int minB4, sumB4;
        if (i > 0) {
            minB4 = pm9x[i - 1];
            sumB4 = ps9x[i - 1];
        } else {
            minB4 = INF9;
            sumB4 = 0;
        }

        int combine2 = a1x[i] + a1x[i + 1];
        int minTake;
        if (minB4 < combine2) {
            minTake = minB4;
        } else {
            minTake = combine2;
        }

        if (sumB4 + minTake < res5) {
            res5 = sumB4 + minTake;
        }
    }

    cout << res5 <<endl;
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

