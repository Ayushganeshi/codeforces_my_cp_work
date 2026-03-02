#include <bits/stdc++.h>
using namespace std;

//author:: Ayush Kumar Gupta;
//chess &&& codee

using ll = long long;
const ll inf = LLONG_MAX / 2;

ll f(const vector<ll>& a) {
    if (a.empty()) return 0;
    if (a.back() == 1) return 5;
    int n = a.size();
    int mod6 = a[0] % 6;
    vector<ll> groups[7];
    for (ll x : a) {
        if (x % 6 != mod6) return inf;
        groups[(x - mod6) / 6 % 7].push_back(x);
    }
    ll ans = inf;
    for (int r = 0; r < 7; r++) {
        ll k = (42 - 6*r - mod6) % 42;
        vector<ll> next;
        for (ll x : groups[r]) next.push_back((x + k) / 42);
        ll rec = f(next);
        if (rec >= inf) continue;
        ans = min(ans, k + 42 * rec);
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    ll res = f(a);
    if (res >= inf) cout << "-1\n";
    else cout << res <<endl;
}
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
