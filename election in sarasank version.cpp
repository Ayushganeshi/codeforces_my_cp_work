#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
#include <immintrin.h>

using namespace __gnu_pbds;
using namespace std;

#define eps 1e-7
#define MOD2 119 * (1ll << 23) + 1
#define int long long
#define mp make_pair
#define pll pair <long long, long long>
#define next return
#define skip continue
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define f first
#define max_of max_element
#define min_of min_element
#define s second

int scan() {
    int x;
    cin >> x;
    return x;
}

string read() {
    string s;
    cin >> s;
    return s;
}

const int N = 1e6 + 2, MOD = 1e9 + 7;
int lp[N], a[N], x, n, v[N];
vector<int> pr, divs[N];

int MAX_V = -1E9;

int solve_for_prime(int vp) {
    int mx_pref = 0;
    int S = 0;
    for (int i = 1; i <= n; i++) S += v[i];
    S = min(S, 36ll);
    int dp[MAX_V + 1][MAX_V + S + 2];
    int old_pref_sum[MAX_V + 1][MAX_V + S + 2];
    int old_pref_sum2[MAX_V + 1][MAX_V + S + 2];
    memset(dp, 0, sizeof dp);
    memset(old_pref_sum, 0, sizeof old_pref_sum);
    memset(old_pref_sum2, 0, sizeof old_pref_sum2);
    int sum = 0;
    dp[0][0] = 1;
    for (int i = 0; i <= n; i++) {
        for (int sum_vp = 0; sum_vp <= S && i > 0; sum_vp++) {
            for (int new_max = 1; new_max <= min(sum_vp, v[i]); new_max++) {
                dp[new_max][sum_vp] += old_pref_sum2[new_max - 1][sum_vp - new_max];
                if (dp[new_max][sum_vp] >= MOD) dp[new_max][sum_vp] -= MOD;
            }
            for (int old_max = 0; old_max <= min(mx_pref, sum_vp); old_max++) {
                dp[old_max][sum_vp] += (old_pref_sum[old_max][sum_vp] + MOD - (sum_vp - min(old_max, v[i]) - 1 < 0 ? 0 :
                                                                              old_pref_sum[old_max][sum_vp - min(old_max, v[i]) - 1])) % MOD;
                //if (dp[old_max][sum_vp] >= MOD) dp[old_max][sum_vp] -= MOD;

            }
        }
        for (int old_max = 0; old_max <= MAX_V; old_max++) {
            for (int j = 0; j <= MAX_V + S; j++) {
                old_pref_sum[old_max][j] = 0;
                old_pref_sum[old_max][j] = (!j ? dp[old_max][j] : old_pref_sum[old_max][j - 1] + dp[old_max][j]);
                if (old_pref_sum[old_max][j] >= MOD) old_pref_sum[old_max][j] -= MOD;
            }
        }
        for (int j = 0; j <= MAX_V + S; j++) {
            for (int old_max = 0; old_max <= MAX_V; old_max++) {
                old_pref_sum2[old_max][j] = 0;
                old_pref_sum2[old_max][j] = (!old_max ? dp[old_max][j] : old_pref_sum2[old_max - 1][j] + dp[old_max][j]);
                if (old_pref_sum2[old_max][j] >= MOD) old_pref_sum2[old_max][j] -= MOD;
                if(i != n) dp[old_max][j] = 0;
            }
        }
        mx_pref = max(mx_pref, v[i]);
    }
    int ret = 0;
    for (int mx = 1; vp + mx <= S && mx <= MAX_V; mx++) {
        ret = (ret + dp[mx][vp + mx]);
        if (ret >= MOD) ret -= MOD;
    }
    return ret;
}

int solveF2_AUTHOR() {
    map<int, int> cnt_pr;
    int cur_x = x;
    while (cur_x > 1) {
        int next_div = lp[cur_x];
        cnt_pr[next_div]++;
        cur_x /= next_div;
    }
    int ans = 1;
    for (auto [prime, cnt]: cnt_pr) {
        MAX_V = -1e9;
        for (int i = 1; i <= n; i++) {
            cur_x = a[i];
            v[i] = 0;
            while (cur_x % prime == 0) {
                v[i]++;
                cur_x /= prime;
            }
            MAX_V = max(MAX_V, v[i]);
        }
        ans = (ans * solve_for_prime(cnt)) % MOD;
    }
    map <int, int> cnt;
    int mx = *max_element(a + 1, a + n + 1);
    set <int> setik;
    for (int i = 1; i <= n; i++) {
        int val = a[i];
        cur_x = val;
        while (cur_x > 1) {
            cnt[lp[cur_x]]++;
            setik.insert(lp[cur_x]);
            cur_x /= lp[cur_x];
        }
    }
    for (auto prime: setik) {
        //if (2 * prime > mx) break;
        int sum = 1;
        if (x % prime != 0) ans = (ans * (cnt[prime] + 1)) % MOD;
    }
    return ans;
}


int32_t main() {
    for (int i = 2; i < N; i++) {
        if (lp[i] == 0) {
            pr.push_back(i);
            lp[i] = i;
        }
        for (int j = 0; j < (int) pr.size() && pr[j] <= lp[i] && i * pr[j] < N; j++) {
            lp[i * pr[j]] = pr[j];
        }
    }
    int t = scan();
    while (t--) {
        n = scan(), x = scan();
        for (int i = 1; i <= n; i++) a[i] = scan();
        cout << solveF2_AUTHOR() << '\n';
    }
}
