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

        vector<int> ans;

        for (int i = 0; i < n; i++) {
            ans.push_back(2 * i + 1);
        }

        for (int x : ans) {
            cout << x << " ";
        }

        cout << '\n';
    }

    return 0;
}
