#include<bits/stdc++.h>

using namespace std;

#define int long long

const int MOD = 998'244'353;

int get0(int x){
    return 1ll + (x >= 3 ? (x - 3) / 4 + 1 : 0);
}

int get1(int x){
    return (x >= 1 ? (x - 1) / 4 + 1 : 0);
}

void solve(){
	int n, x;
	cin >> n >> x;

    int l0 = get0(x - 1) % MOD;
    int r0 = (get0(n) - l0) % MOD;
	int ans = l0 * r0;

    int l1 = get1(x - 1) % MOD;
    int r1 = (get1(n) - l1) % MOD;
	ans += l1 * r1;
    ans %= MOD;

    cout << ans << '\n';
}

signed main()
{
#ifdef FELIX
	auto _clock_start = chrono::high_resolution_clock::now();
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int tests = 1;
	cin >> tests;
	while(tests--){
		solve();
	}

#ifdef FELIX
	cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
		chrono::high_resolution_clock::now()
			- _clock_start).count() << "ms." << endl;
#endif
	return 0;
}
