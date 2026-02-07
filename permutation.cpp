#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> p;
        p.push_back(1);
        p.push_back(n);

        vector<bool> used(n + 1, false);
        used[1] = true;
        used[n] = true;

        for (int i = n - 2; i > 0; --i) {
            int prev = p.back();
            if (prev - i >= 1 && prev - i <= n && !used[prev - i]) {
                p.push_back(prev - i);
                used[prev - i] = true;
            } else {
                p.push_back(prev + i);
                used[prev + i] = true;
            }
        }

        reverse(p.begin(), p.end());

        for (int i = 0; i < n; ++i) {
            cout << p[i] << (i + 1 < n ? ' ' : '\n');
        }
    }

    return 0;
}
