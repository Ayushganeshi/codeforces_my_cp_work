#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int n;
    cin >> n;

    string s;
    cin >> s;

    s = " " + s;

    vector<int> a(n + 1), b(n + 1), c(n + 1);
    vector<int> vis(n + 1, 0);

    vis[0] = 1;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }

    c[0] = -1e18;
    b[0] = 0;

    for (int i = 1; i <= n; i++) {

        if (c[i] != c[i - 1]) {

            if (c[i] < c[i - 1]) {
                cout << "No\n";
                return;
            }

            b[i] = c[i];
            vis[i] = 1;

            for (int j = i; j >= 1; j--) {

                if (s[j] == '1') {

                    if (vis[j - 1] && b[j - 1] + a[j] != b[j]) {
                        cout << "No\n";
                        return;
                    }

                    vis[j - 1] = 1;
                    b[j - 1] = b[j] - a[j];
                }
                else {
                    break;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {

        if (s[i] == '1') {
            b[i] = b[i - 1] + a[i];
            vis[i] = 1;
        }

        if (!vis[i]) {
            b[i] = -1e16;
        }

        a[i] = b[i] - b[i - 1];

        if (max(c[i - 1], b[i]) != c[i]) {
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";

    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }

    cout << '\n';
}

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}
