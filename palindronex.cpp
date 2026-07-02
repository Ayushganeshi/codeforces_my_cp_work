#include <bits/stdc++.h>

using namespace std;

pair<int, int> ok(int x, int d, int e) {
    pair<int, int> ans;
    int l = d, r = 100000;
    while (l != r) {
        int m = (l + r) / 2;
        if ((x + (m / d) - 1) / (m / d) <= e) r = m;
        else l = m + 1;
    }
    ans.first = r;
    l = d, r = 100000;
    while (l != r) {
        int m = (l + r + 1) / 2;
        if ((x + (m / d) - 1) / (m / d) >= e) l = m;
        else r = m - 1;
    }
    ans.second = l;
    return ans;
}

int main() {
    int t;
    for (cin >> t; t--;) {
        int d = 123, x = 8257;
        cout << "? " << x;
        for (int i = 0; i < x; ++i) cout << ' ' << d + 1;
        cout << endl;
        int t;
        cin >> t;
        if (t) {
            auto [l, r] = ok(x, d, t);
            cout << "? " << (r - l) * 2;
            for (int i = l; i < r; ++i) cout << ' ' << i << ' ' << i - l + 1;
            cout << endl;
            cin >> t;
            cout << "! " << 2 * r - t - l << endl;
        } else {
            cout << "? " << d * d;
            for (int i = 0; i < d * d; ++i) cout << ' ' << 1;
            cout << endl;
            cin >> t;
            auto [l, r] = ok(d * d, 1, t);
            cout << "! " << l << endl;
        }
    }
}
