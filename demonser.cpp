#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n);

        for (auto &x : a) {
            cin >> x;
            --x;
        }

        for (auto &x : b) {
            cin >> x;
            --x;
        }

        vector<int> pa(n + 1, n), pb(n + 1, n), dp(n + 1, n);

        long long ans = 0;

        for (int i = n - 1; i >= 0; --i) {
            pa[a[i]] = i;
            pb[b[i]] = i;

            if (a[i] == b[i]) {
                int x = a[i] + 1;

                if (x <= n) {
                    if (pa[x] == pb[x]) {
                        dp[i] = dp[pa[x]];
                    } else {
                        dp[i] = min(pa[x], pb[x]);
                    }
                }
            }

            if (pa[0] != pb[0]) {
                ans += min(pa[0], pb[0]) - i;
            } else {
                ans += dp[pa[0]] - i;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
