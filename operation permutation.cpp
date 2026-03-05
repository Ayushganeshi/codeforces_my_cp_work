#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9+7;

ll mpow(ll a, ll b) {
    ll r = 1;
    while (b) {
        if (b & 1) {
            r *= a;
            r %= mod;
        }
        b >>= 1;
        a *= a;
        a %= mod;
    }
    return r;
}

ll inv(ll a) {
    return mpow(a, mod-2);
}

const int maxn = 5000;
ll facts[maxn+1] = {1};

void precomp() {
    for (int i = 1; i <= maxn; i++) {
        facts[i] = facts[i-1] * i % mod;
    }
}

void solve() {
    int n;
    ll x;
    cin >> n >> x;

    vector<ll> mults;
    ll adds = 0;
    for (int i = 0; i < n; i++) {
        char c;
        ll v;
        cin >> c >> v;
        if (c == '-') adds += mod - v;
        else if (c == '+') adds += v;
        else if (c == '/') mults.push_back(inv(v));
        else mults.push_back(v);
    }
    adds %= mod;

    // solve
    int m = mults.size();
    vector<ll> dp(m+1);
    dp[0] = 1;
    for (auto &b : mults) {
        x *= b;
        x %= mod;
        for (int i = m; i >= 1; i--) {
            dp[i] += dp[i-1] * b;
            dp[i] %= mod;
        }
    }

    ll S = 0;
    for (int i = 0; i <= m; i++) {
        S += dp[i] * facts[i] % mod * facts[m-i] % mod * inv(facts[m]) % mod;
        S %= mod;
    }
    S *= inv(m+1);
    S %= mod;

    // answer
    ll ans = x + adds * S;
    ans %= mod;
    cout << ans << "\n";
}

signed main() {
    precomp();
    int t = 1;
    cin >> t;
    while (t--) solve();
}
